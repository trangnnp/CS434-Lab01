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

QByteArray sendConv(string data, string tag) {
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

   Player player;
   player.id = room.players.size();
   player.name = strdup("meo");
   player.clientSocket = clientSocket;
   room.players.push_back(player);

    for (Player player : room.players) {
        if (player.clientSocket != clientSocket) {
            player.clientSocket->write(sendConv(clientSocket->peerAddress().toString().toStdString() + " User " + to_string(room.players.size()-1) + " connected to server !\n","N"));
        } else {
            player.clientSocket->write(sendConv(clientSocket->peerAddress().toString().toStdString() + " Hello User " + to_string(player.id) + " !\n","N"));
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
        qDebug() << i;
        for (Player player : room.players) {
            string packQuestion = "Q=" + string(room.packs.at(i).q)+"\~" + "A=" + string(room.packs.at(i).a)+"\~"
                    + "B=" + string(room.packs.at(i).b)+"\~" + "C=" + string(room.packs.at(i).c)+"\~"
                    "D=" + string(room.packs.at(i).d)+"\~";
            QByteArray dataSend = sendConv(packQuestion,"Q");
            player.clientSocket->write(dataSend);

        }

        if (!isOnGame) {
            return;
        }
    }
}


void MainWindow::onReadyRead()
{
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    QByteArray datas = sender->readAll();
    for (QTcpSocket* socket : _sockets) {
        if (socket != sender) {
            socket->write(QByteArray::fromStdString(sender->peerAddress().toString().toStdString() + ": hello from server"));
            qDebug() << sender->peerAddress();
        }
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
