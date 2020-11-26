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
#include <QQmlContext>
#include <QQmlEngine>
#include "playerlist.h"
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include "testt.h"

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

void MainWindow::checkAnwer(int correct) {
//color: client.aResult===0 ? choosen : client.aResult===1 ? correct : client.aResult===2 ? correctans : client.aResult ==4 ? wrongans : normal

    if (correct == 0) if (aResult==0) aResult=1; else aResult=2;
    if (correct == 1) if (bResult==0) bResult=1; else bResult=2;
    if (correct == 2) if (cResult==0) cResult=1; else cResult=2;
    if (correct == 3) if (dResult==0) dResult=1; else dResult=2;

    if (aResult == 0 and correct!=0) aResult=4;
    if (bResult == 0 and correct!=1) bResult=4;
    if (cResult == 0 and correct!=2) cResult=4;
    if (dResult == 0 and correct!=3) dResult=4;
    qDebug() << aResult;
    qDebug() << bResult;
    qDebug() << cResult;
    qDebug() << dResult;


    resultUpdated();
}

void MainWindow::onReadyRead() {
    QByteArray datas = _socket.readAll();
    string data = datas.toStdString();
    qDebug() << QByteArray::fromStdString("datas: ") + datas;

    vector<pair<string,string>> vec;
    string delimiter = "\n";
    splitS(data.append("##"),vec,delimiter);

    qDebug() << vec.size();

    for (auto i: vec) {
        qDebug() << QByteArray::fromStdString("first: ") + i.first[0];
        qDebug() << QByteArray::fromStdString("second: "+ i.second);
        switch(i.first[0]) {
            case 'N':
                qDebug() << QByteArray::fromStdString(i.second);
                break;
            case 'Q':
                splitQ(i.second);
                break;
            case 'K':
                qDebug() << QByteArray::fromStdString(i.second);
                checkAnwer(atoi(i.second.c_str()));
                break;
            case 'E':
                qDebug() << QByteArray::fromStdString(i.second);
                break;
            case 'J':
                qDebug() << QByteArray::fromStdString(i.second);
                break;
            case 'P':
                qDebug() << QByteArray::fromStdString(i.second);
//                addNewPlayer(i.second);

                break;
        }
    }
}

void MainWindow::addNewPlayer(string data) {
    singletonData->playerList.resetItems();

    vector<pair<string,string>> vec;
    string delimiter = "*";
    splitS(data.append("##"), vec, delimiter);
    for (auto i: vec) {
        string info = i.second;
        qDebug() << QByteArray::fromStdString(info);

        Player p = Player();
        int current = info.find_first_of('-');
        p.name = QByteArray::fromStdString(info.substr(0,current-1));
        int previous = current + 1;
        current = info.find_first_of('-', previous);
        p.avatar = QByteArray::fromStdString(info.substr(0,current-1));
        p.score = 0;

        qDebug() << p.name;

        singletonData->playerList.appendItem(p);
    }

//

//    p.name = QByteArray::fromStdString(data.substr(0,current-1));
//    int previous = current + 1;
//    current = data.find_first_of('-', previous);
//    p.avatar = QByteArray::fromStdString(data.substr(0,current-1));
//    p.score = 0;

//    playerList.appendItem(p);
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
