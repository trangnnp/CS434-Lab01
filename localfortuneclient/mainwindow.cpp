#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QHostAddress>
#include <QStackedWidget>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <QObject>

MainWindow::MainWindow(QObject *parent):QObject(parent) {
    _socket.connectToHost(QHostAddress("127.0.0.1"), 4242);
    connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
//    createMe(QByteArray::fromStdString("Meo" + to_string(rand()%10)));
//    curPack.q = QByteArray::fromStdString("bbbbbbbbbbbbbbbbbbbbb");
    qDebug() << "Constructor Done!";
}

void MainWindow::printMessage(QString txt)
{
qDebug() << "Message from QML: " << txt;
}


MainWindow::~MainWindow() {
//    delete ui;
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


void MainWindow::splitQ(const string& str) {
    const string& delims = "\~";
    std::size_t current, previous = 0;
    current = str.find_first_of(delims);

    curPack.q = QByteArray::fromStdString(str.substr(previous+2,current - previous-2));
    previous = current + 1;
    current = str.find_first_of(delims,previous);

    curPack.a = QByteArray::fromStdString(str.substr(previous+2,current - previous-2));
    previous = current + 1;
    current = str.find_first_of(delims,previous);

    curPack.b = QByteArray::fromStdString(str.substr(previous+2,current - previous-2));
    previous = current + 1;
    current = str.find_first_of(delims,previous);

    curPack.c = QByteArray::fromStdString(str.substr(previous+2,current - previous-2));
    previous = current + 1;
    current = str.find_first_of(delims,previous);

    curPack.d = QByteArray::fromStdString(str.substr(previous+2,current - previous-3));
    curPackChanged();

    qDebug() << curPack.q;
    qDebug() << curPack.a;
    qDebug() << curPack.b;
    qDebug() << curPack.c;
    qDebug() << curPack.d;
}

void MainWindow::onReadyRead() {
//    while (_socket.canReadLine()) {
        QByteArray datas = _socket.readAll();
        string data = datas.toStdString();
        qDebug() << QByteArray::fromStdString("datas: ") + datas;

        vector<pair<string,string>> vec;
        string delimiter = "\n";
        splitS(data.append("##"),vec,delimiter);

        qDebug() << vec.size();


        for (auto i: vec) {
//            Pack *question = new Pack();
            qDebug() << QByteArray::fromStdString("first: ") + i.first[0];
            qDebug() << QByteArray::fromStdString("second: "+ i.second);
            switch(i.first[0]) {
                case 'N':
                    qDebug() << QByteArray::fromStdString(i.second);
                    break;
                case 'Q':
                    splitQ(i.second);
//                    question.onGame();
//                    sendAnswer(rand() % 4);
                    break;
                case 'K':
                    qDebug() << QByteArray::fromStdString(i.second);
                    break;
            }
        }

//    }
}


void MainWindow::sendAnswer(int answer) {
    _socket.write(sendConv(to_string(answer), "W"));
    qDebug() << "Sent";
}


void MainWindow::on_pushButton_clicked()
{
    QString mString;
    mString = ui->lineEdit->text();
    ui->lineEdit->setText("");
    createMe(mString);
    // change man hinh
    qDebug() << mString;
}

void MainWindow::createMe(QString name) {
    _socket.write(sendConv(name.toStdString(), "J"));
}
