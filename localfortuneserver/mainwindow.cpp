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

    room.name = (char*)"Default Room Name";

    _server.listen(QHostAddress::Any, 4242);
    connect(&_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

MainWindow::~MainWindow()
{
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

    for (int i=0; i<room.packs.size(); i++) {
        qDebug() << QByteArray::fromStdString("Sending " + to_string(i));
        room.curPackId++;
        for (Player player : room.players) {
            qDebug() << QByteArray::fromStdString("send to player: " + to_string(player.id));
            string packQuestion = "Q=" + string(room.packs.at(i).q)+"\~" + "A=" + string(room.packs.at(i).a)+"\~"
                    + "B=" + string(room.packs.at(i).b)+"\~" + "C=" + string(room.packs.at(i).c)+"\~"
                    "D=" + string(room.packs.at(i).d)+"\~";
            QByteArray dataSend = sendConv(packQuestion,"Q");
            player.clientSocket->write(dataSend);

        }

        if (!isOnGame) {
            return;
        }

        qDebug() << QByteArray::fromStdString("lan " + to_string(i));
    }
}

void MainWindow::collectAnswer(int answer, QTcpSocket* socket) {
    qDebug() << "======collectAnswer======";
    for (Player player : room.players) {
        if (player.clientSocket == socket) {
            qDebug() << "======found player======";
            if (player.stauts == 2) {
                socket->write(sendConv("You cannot answer this question!","N"));
                return;
            }

            if (answer == room.packs.at(room.curPackId).correct) {
                socket->write(sendConv("You right!","K"));
            } else {
                socket->write(sendConv("You wrong!","K"));
                if (++player.stauts == 2) {
                    socket->write(sendConv("Chet!","N"));
                }
            }
            return;
        }
    }
}

void MainWindow::sendCorrectAnswer() {
    for (Player player : room.players) {
        player.clientSocket->write(sendConv("The correct answer is " + to_string(room.packs.at(room.curPackId).correct) + " ! ","K"));
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
    Player player;
    player.id = room.players.size();
    player.name = name;
    player.clientSocket = socket;
    room.players.push_back(player);
    qDebug() << QByteArray::fromStdString("Add new player: " + name);

     for (Player player : room.players) {
         if (player.clientSocket != socket) {
             player.clientSocket->write(sendConv(" Player " + name + " has just joined !\n","N"));
         } else {
             player.clientSocket->write(sendConv(" Hello " + name + " !\n","N"));
         }
     }

     if (room.players.size() == 1) {
         isOnGame = true;
         getPacksForRoom(&room);
         qDebug() << room.packs.size();
         for (Player player : room.players) {
             player.clientSocket->write(sendConv("\n\n================== Game Starting ======================\n","N"));
         }
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
