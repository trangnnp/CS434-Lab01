#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QHostAddress>
#include <QAbstractSocket>
#include<iostream>
#include "player.h"
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _server(this)
{
    ui->setupUi(this);
    qDebug() << "Start server";
    qDebug() << packBank.packs.size();

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

   connect(clientSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
   connect(clientSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));

   Player player;
   player.id = _sockets.size();
   player.name = strdup("meo");
   player.clientSocket = clientSocket;
   players.push_back(player);

    _sockets.push_back(clientSocket);
    for (QTcpSocket* socket : _sockets) {
        if (socket != clientSocket) {
            socket->write(QByteArray::fromStdString(clientSocket->peerAddress().toString().toStdString() + " User " + to_string(player.id) + " connected to server !\n"));
        } else {
            socket->write(QByteArray::fromStdString(clientSocket->peerAddress().toString().toStdString() + " Hello User " + to_string(player.id) + " !\n"));
        }
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
