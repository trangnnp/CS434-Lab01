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

void MainWindow::onNewConnection()
{
   QTcpSocket *clientSocket = _server.nextPendingConnection();

   if (isOnGame) {
       clientSocket->write(QByteArray::fromStdString("Game is started! Connection rejected!\n"));
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
            player.clientSocket->write(QByteArray::fromStdString(clientSocket->peerAddress().toString().toStdString() + " User " + to_string(room.players.size()-1) + " connected to server !\n"));
        } else {
            player.clientSocket->write(QByteArray::fromStdString(clientSocket->peerAddress().toString().toStdString() + " Hello User " + to_string(player.id) + " !\n"));
        }
    }

    if (room.players.size() == 3) {
        isOnGame = true;
        getPacksForRoom(&room);
        qDebug() << room.packs.size();
        for (Player player : room.players) {
            player.clientSocket->write(QByteArray::fromStdString("\n\n================== Game Starting ======================\n"));
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
            player.clientSocket->write(QByteArray::fromStdString("Q=" + string(room.packs.at(i).q)));
            player.clientSocket->write(QByteArray::fromStdString("A=" + string(room.packs.at(i).a)));
            player.clientSocket->write(QByteArray::fromStdString("B=" + string(room.packs.at(i).b)));
            player.clientSocket->write(QByteArray::fromStdString("C=" + string(room.packs.at(i).c)));
            player.clientSocket->write(QByteArray::fromStdString("D=" + string(room.packs.at(i).d)));
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
