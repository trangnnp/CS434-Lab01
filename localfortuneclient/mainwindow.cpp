#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QHostAddress>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

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

template <class Container>
void splitS(const string& str, Container& cont,
              const string& delims = "\n")
{
    std::size_t current, previous, mid = 0;
    previous = str.find_first_of("##");
    mid = str.find_first_of("%%",previous);
    current = str.find_first_of("##",previous+2);


    pair<string,string> packet;
    while (current != std::string::npos) {
        packet.first = str.substr(previous+2, mid - previous - 2);
        packet.second = str.substr(mid + 2, current - mid - 2);
        cont.push_back(packet);
        previous = current + 2;
        current = str.find_first_of("##", previous);
        mid = str.find_first_of("%%",previous);
    }
}

void MainWindow::onReadyRead() {
    while (_socket.bytesAvailable() > 0) {
        QByteArray datas = _socket.readAll();
    //    qDebug() << datas;
        string data = datas.toStdString();
    //    data.erase(data.begin(), data.begin()+1);
//        qDebug() << QByteArray::fromStdString(data);

        vector<pair<string,string>> vec;
        string delimiter = "\n";
        splitS(data,vec,delimiter);


        for (auto i: vec) {
            qDebug() << QByteArray::fromStdString(i.second);
        }

    }


//    switch(datas[0]) {
//        case 'Q':
//          curPack.q = data;
//          break;
//        case 'A':
//          curPack.a = data;
//          break;
//        case 'B':
//          curPack.b = data;
//          break;
//        case 'C':
//          curPack.c = data;
//          break;
//        case 'D':
//          curPack.d = data;
//          break;
//        case 'K':
//          stringstream geek(data);
//          geek >> curPack.correct;
//          break;
//    }

//    qDebug() << QByteArray::fromStdString(curPack.q);
//    qDebug() << QByteArray::fromStdString(curPack.a);
//    qDebug() << QByteArray::fromStdString(curPack.b);
//    qDebug() << QByteArray::fromStdString(curPack.c);
//    qDebug() << QByteArray::fromStdString(curPack.d);
}
