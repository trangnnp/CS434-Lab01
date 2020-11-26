#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QHostAddress>
#include <QAbstractSocket>
#include<iostream>
#include "player.h"
#include <string>
#include <string.h>
#include <set>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _server(this)
{
    ui->setupUi(this);
    qDebug() << "Start server";
    qDebug() << packBank.packs.size();

    room->name = (char*)"Default Room Name";

    _server.listen(QHostAddress::Any, 4242);
    connect(&_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

MainWindow::~MainWindow()
{
    room->isOnGame = false;
    if (!room->isFinished()) {
        room->terminate();
    }

    delete ui;
}

template <class Container>
void splitS(const string& str, Container& cont,
              const string& delims = "\n")
{
    std::size_t current, previous, mid = 0;
    previous = str.find_first_of("##");
    mid = str.find_first_of("%%",previous);
    current = min(str.length(), str.find_first_of("##",previous+2));

    pair<string,string> packet;
    while (current != std::string::npos) {
        packet.first = str.substr(previous+2, mid - previous - 2);
        packet.second = str.substr(mid + 2, current - mid - 2);
        cont.push_back(packet);
        previous = current;
        current = str.find_first_of("##", previous+2);
        mid = str.find_first_of("%%",previous);
    }
}

QByteArray MainWindow::sendConv(string data, string tag) {
    return QByteArray::fromStdString("##"+tag+"%%"+data);
}

void MainWindow::onNewConnection()
{
   QTcpSocket *clientSocket = _server.nextPendingConnection();

   if (isOnGame) {
       clientSocket->write(sendConv("Game is started! Connection rejected!\n","N"));
       clientSocket->close();
       return;
   }

   connect(clientSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
   connect(clientSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));
}

void MainWindow::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
        _sockets.removeOne(sender);
    }
}

void MainWindow::onGame() {
    connect(room, SIGNAL(sendSignal()),this,SLOT(sendData()));
    room->isOnGame = true;
    room->start();

    room->sendAll(sendConv("\n\n================== Game Starting ======================\n","N"));
    room->sendRoomInfo();
}

void MainWindow::collectAnswer(int answer, QTcpSocket* socket) {
    qDebug() << "======collectAnswer======";
    for (Player &player : room->players) {
        if (player.clientSocket == socket) {
            qDebug() << "======found player======";
            if (player.stauts == 2) {
                socket->write(sendConv("You cannot answer this question!","N"));
                return;
            }

            socket->write(sendConv(to_string(room->packs.at(room->curPackId).correct),"K"));
            qDebug() << "======ready update scores======";
            socket->write(sendConv("really?","N"));
            if (answer == room->packs.at(room->curPackId).correct) {
                socket->write(sendConv("You right!","N"));
                player.score+=room->scorePerPack;
                qDebug() << player.score;
            } else {
                socket->write(sendConv("You wrong!","N"));
                if (++player.stauts == 2) {
                    socket->write(sendConv("Chet!","N"));
                }
            }
            room->sendPlayersInfo();
            return;
        }
    }
}

void MainWindow::sendCorrectAnswer() {
    room->sendAll(sendConv("The correct answer is " + to_string(room->packs.at(room->curPackId).correct) + " ! ","K"));
}

void MainWindow::sendData() {
    for (Player player : room->players) {
        player.clientSocket->write(room->sendData);
    }
}

void MainWindow::onReadyRead() {
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    QByteArray datas = sender->readAll();
    string data = datas.toStdString();
    qDebug() << QByteArray::fromStdString("datas: ") + datas;

    vector<pair<string,string>> vec;
    string delimiter = "\n";
    splitS(data.append("##"),vec,delimiter);

    for (auto i: vec) {
        qDebug() << QByteArray::fromStdString("first: ") + i.first[0];
        qDebug() << QByteArray::fromStdString("second: "+ i.second);
        switch(i.first[0]) {
            case 'J':
                addNewPlayer(i.second, sender);
                break;
            case 'W':
                sender->write(sendConv("Your answer is: " + i.second + " ! ","N"));
                collectAnswer(stoi(i.second), sender);
                break;
        }
    }
}

void MainWindow::addNewPlayer(string name, QTcpSocket* socket) {
    for (Player player : room->players) {
        if (strcmp(name.c_str(), player.name.c_str()) == 0) {
            socket->write(sendConv("Name is not available!","E"));
            return;
        }
    }

    Player player;
    player.id = room->players.size();
    player.name = name;
    player.clientSocket = socket;
    player.avatar = colors[rand() % 4];
    room->players.push_back(player);
    qDebug() << QByteArray::fromStdString("Add new player: " + name);

     string data = room->playersInfo();
     for (Player player : room->players) {
         if (player.clientSocket != socket) {
             player.clientSocket->write(sendConv(" Player " + name + " has just joined !\n","N"));
         } else {
             player.clientSocket->write(sendConv(" Hello " + name + " !\n","J"));
         }
         player.clientSocket->write(sendConv(data, "P"));
     }

     if (room->players.size() >= room->maxPlayer) {
         isOnGame = true;
         getPacksForRoom(room);
         qDebug() << room->packs.size();
         onGame();
     }

}


void MainWindow::getPacksForRoom(Room *room) {
    set<int> numbers;
    while (numbers.size() < room->limitPacks) {
       numbers.insert(rand() % room->maxPacks);
    }

    for (int i: numbers) {
        room->packs.push_back(packBank.packs.at(i));
    }
}
