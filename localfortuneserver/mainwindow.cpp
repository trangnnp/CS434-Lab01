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
#include <QObject>

using namespace std;

MainWindow::MainWindow(QObject *parent):QObject(parent),
    _server(this)
{
    qDebug() << "Start server";
    qDebug() << packBank.packs.size();

    connect(timerTurn, &QTimer::timeout, this, &MainWindow::updatepackTimerValue);
}

MainWindow::~MainWindow()
{
    room->isOnGame = false;
    if (!room->isFinished()) {
        room->terminate();
    }

    delete ui;
}

void MainWindow::createRoom(){
    initRoom();
    _server.listen(QHostAddress::Any, 4242);
    connect(&_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

void MainWindow::updatepackTimerValue() {
    room->isNext = true;
    timerTurn->stop();
}

void MainWindow::resetRoom() {
    if (startStatus == 1) {
        isOnGame = true;
        getPacksForRoom(room);
        startStatus = 2;
        onStartStatusChanged();
        qDebug() << room->packs.size();
        onGame();
    } else {
        if (startStatus == 3) {
            isOnGame = true;
            getPacksForRoom(room);
            startStatus = 1;
            onStartStatusChanged();
            qDebug() << room->packs.size();

            for (Player p: room->players) {
                p.score = 0;
                p.skipped = false;
                p.status = 0;
            }

            room->sendPlayersInfo();
        }
    }
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
    countActive = room->players.size();
    qDebug() << "======countActive======";
    qDebug() << countActive;
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
            if (player.status == 2) {
                socket->write(sendConv("You cannot answer this question!","N"));
                return;
            }

            socket->write(sendConv(to_string(room->packs.at(room->curPackId).correct),"K"));
            qDebug() << "======ready update scores======";
            if (answer == room->packs.at(room->curPackId).correct) {
                socket->write(sendConv("You right!","N"));
                player.score+=room->scorePerPack;
                room->packs.at(room->curPackId).answered = true;
                qDebug() << player.score;
            } else {
                if (answer == -1) {
                    if (player.skipped == false) {
                        socket->write(sendConv("1 more chance","N"));
                        player.skipped = true;
                    } else {
                        player.status = 2;
                        socket->write(sendConv("Chet!","N"));
                        countActive--;
                    }

                } else {
                    socket->write(sendConv("You are wrong!","N"));
                    room->packs.at(room->curPackId).answered = true;
                    player.status = 2;
                    socket->write(sendConv("Chet!","N"));
                    countActive--;
                }
            }

            qDebug() << "======countActive======";
            qDebug() << countActive;

            if (countActive <= 1 || room->curPackId == room->packs.size()-1) {
                endGame();
            }

            room->sendPlayersInfo();
            updatePlayerInfo();
            room->isNext = true;
            return;
        }
    }
}

void MainWindow::endGame() {
    room->isOnGame = false;
    int highestScore = 0;

    for (Player p:room->players){
        if (p.status != 2) {
            if (p.score > highestScore) highestScore = p.score;
        }
    }

    for (Player p:room->players){
        if (p.status != 2 && p.score == highestScore) {
            p.status = 3;
        } else {
            p.status = 4;
        }
    }

    updatePlayerInfo();
    room->sendAll(sendConv("Game Ended", "Y"));

    startStatus = 3;
    onStartStatusChanged();
}

void MainWindow::sendCorrectAnswer() {
    room->sendAll(sendConv("The correct answer is " + to_string(room->packs.at(room->curPackId).correct) + " ! ","N"));
}

void MainWindow::sendData() {
    room->sendAll(room->sendData);
    updatePack();
}

void MainWindow::updatePack() {
    packq = room->packq;
    packa = room->packa;
    packb = room->packb;
    packc = room->packc;
    packd = room->packd;
    correct = room->kotae;
    onCurPackChanged();
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
        addNewMsg(i.second, getSenderFromConnection(sender));
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

    socket->write(sendConv("OK!","O"));

    Player player;
    player.id = room->players.size();
    player.name = name;
    player.clientSocket = socket;
    player.avatar = colors[rand() % colors->size()];
    room->players.push_back(player);
    qDebug() << QByteArray::fromStdString("Add new player: " + name);
    updatePlayerInfo();

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
         startStatus = 1;
         onStartStatusChanged();
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


void MainWindow::addNewMsg(string data, string sender) {
    Msg msg = Msg();
    msg.timestamp = QByteArray::fromStdString(getTime());
    msg.content = QByteArray::fromStdString(data);
    msg.sender = QByteArray::fromStdString(sender);
    singletonData->msgList.appendItem(msg);
}

string MainWindow::getSenderFromConnection(QTcpSocket *connection) {
    for (Player player: room->players) {
        if (connection == player.clientSocket) return player.name;
    }
    return "GUESS";
}

string MainWindow::getTime() {
    tm * timeinfo;
    time_t rawtime;
    char timebuff[120] = {0};
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timebuff, 12, "%r", timeinfo);
    return string(timebuff);
}


void MainWindow::updatePlayerInfo() {
    singletonData->playerList.resetItems();

    for (auto player: room->players) {
        singletonData->playerList.appendItem(player);
    }

    playerInfoUpdated();
}
