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
#include "singletondata.h"

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

void MainWindow::splitConbinedCmd(vector<string>& res, const string& str, string delims) {
    std::size_t current, previous = 0;
    current = str.find_first_of(delims);

    while (current!=0 && previous <= str.size() - 1) {
        res.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find_first_of(delims,previous);
    }
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
                updatePlayerInfo(i.second);
                break;
        }
    }
}

void MainWindow::updatePlayerInfo(string data) {
    singletonData->playerList.resetItems();
    qDebug() << "==========Update player info============";

    vector<string> players;
    string delimiter = "*";
    splitConbinedCmd(players, data, delimiter);

    for (auto player: players) {
        qDebug() << QByteArray::fromStdString(player);
        vector<string> info;
        splitConbinedCmd(info, player.append("-"), "-");

        Player p = Player();
        p.name =  QByteArray::fromStdString(info.at(0));
        p.score = atoi(info.at(1).c_str());
        p.avatar = QByteArray::fromStdString(info.at(2));

        singletonData->playerList.appendItem(p);
    }
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
