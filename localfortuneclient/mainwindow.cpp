#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QHostAddress>
#include <QStackedWidget>
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


template <class Container>
void splitQ(const string& str, Container& cont,
              const string& delims = "\~")
{
    std::size_t current, previous = 0;
    current = str.find_first_of(delims);

    Pack curPack;
    curPack.q = str.substr(previous,current - previous);
    previous = current + 1;
    current = str.find_first_of(delims,previous);

    curPack.a = str.substr(previous,current - previous);
    previous = current + 1;
    current = str.find_first_of(delims,previous);

    curPack.b = str.substr(previous,current - previous);
    previous = current + 1;
    current = str.find_first_of(delims,previous);

    curPack.c = str.substr(previous,current - previous);
    previous = current + 1;
    current = str.find_first_of(delims,previous);

    curPack.d = str.substr(previous,current - previous);

    qDebug() << QByteArray::fromStdString(curPack.q);
    qDebug() << QByteArray::fromStdString(curPack.a);
    qDebug() << QByteArray::fromStdString(curPack.b);
    qDebug() << QByteArray::fromStdString(curPack.c);
    qDebug() << QByteArray::fromStdString(curPack.d);

    cont.push_back(curPack);
}

void MainWindow::onReadyRead() {
    while (_socket.bytesAvailable() > 0) {
        QByteArray datas = _socket.readAll();
        string data = datas.toStdString();

        vector<pair<string,string>> vec;
        string delimiter = "\n";
        splitS(data,vec,delimiter);

        vector<Pack> questions;

        for (auto i: vec) {
            switch(i.first[0]) {
                case 'N':
                    qDebug() << QByteArray::fromStdString(i.second);
                    break;
                case 'Q':
                    splitQ(i.second,questions);
                    break;
            }
        }

    }
}


void MainWindow::on_pushButton_clicked()
{
    QString mString;
    mString = ui->lineEdit->text();
    ui->lineEdit->setText("");
    createMe(mString.toStdString());
    // change man hinh
    qDebug() << mString;
}

void MainWindow::createMe(string name) {
    _socket.write(sendConv(name, "J"));
}
