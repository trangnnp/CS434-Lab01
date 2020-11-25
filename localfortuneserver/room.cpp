#include "room.h"
#include <iostream>
#include <random>
#include <set>
#include <QDebug>

Room::Room():QThread()
{

}

QByteArray sendConv(string data, string tag) {
    return QByteArray::fromStdString("##"+tag+"%%"+data);
}

void Room::sendAll(QByteArray dataSend) {
    for (Player player : players) {
        player.clientSocket->write(dataSend);
    }
}

void Room::run(){
    qDebug() << "running";
//    sendAll(sendConv("Meooooooooooooooooooooooooooooooooooooo","N"));

    for (int i=0; i<packs.size(); i++) {
        curPackId++;
        qDebug() << QByteArray::fromStdString("Sending " + to_string(curPackId));
        string packQuestion = "Q=" + string(packs.at(i).q)+"\~" + "A=" + string(packs.at(i).a)+"\~"
                            + "B=" + string(packs.at(i).b)+"\~" + "C=" + string(packs.at(i).c)+"\~"
                            "D=" + string(packs.at(i).d)+"\~";
        sendAll(sendConv(packQuestion,"Q"));
    }

//    for (int i=0; i<packs.size(); i++) {
//        qDebug() << QByteArray::fromStdString("Sending " + to_string(i));
//        curPackId++;
//        for (Player player : players) {
//            qDebug() << QByteArray::fromStdString("send to player: " + to_string(player.id));
//            string packQuestion = "Q=" + string(packs.at(i).q)+"\~" + "A=" + string(packs.at(i).a)+"\~"
//                    + "B=" + string(packs.at(i).b)+"\~" + "C=" + string(packs.at(i).c)+"\~"
//                    "D=" + string(packs.at(i).d)+"\~";
//            QByteArray dataSend = sendConv(packQuestion,"Q");
//            qDebug() << dataSend;
//            player.clientSocket->write(dataSend);

//        }

//        if (!isOnGame) {
//            return;
//        }

//        qDebug() << QByteArray::fromStdString("lan " + to_string(i));
//    }
}
