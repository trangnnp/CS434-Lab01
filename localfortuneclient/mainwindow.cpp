#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QHostAddress>
#include <string>
#include <sstream>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _socket(this)
{
    ui->setupUi(this);
    _socket.connectToHost(QHostAddress("127.0.0.1"), 4242);
    connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onReadyRead() {
    QByteArray datas = _socket.readAll();
//    qDebug() << datas;
    string data = datas.toStdString();
    data.erase(data.begin(), data.begin()+1);
    qDebug() << QByteArray::fromStdString(data);

    switch(datas[0]) {
        case 'Q':
          curPack.q = data;
          break;
        case 'A':
          curPack.a = data;
          break;
        case 'B':
          curPack.b = data;
          break;
        case 'C':
          curPack.c = data;
          break;
        case 'D':
          curPack.d = data;
          break;
        case 'K':
          stringstream geek(data);
          geek >> curPack.correct;
          break;
    }

    qDebug() << QByteArray::fromStdString(curPack.q);
    qDebug() << QByteArray::fromStdString(curPack.a);
    qDebug() << QByteArray::fromStdString(curPack.b);
    qDebug() << QByteArray::fromStdString(curPack.c);
    qDebug() << QByteArray::fromStdString(curPack.d);
}
