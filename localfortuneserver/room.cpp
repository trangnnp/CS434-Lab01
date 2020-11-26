/*
 *   Copyright (c) 2020 Trang Ngoc-Phuong Nguyen
 *   All rights reserved.

 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at

 *   http://www.apache.org/licenses/LICENSE-2.0

 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#include "room.h"
#include <iostream>
#include <random>
#include <set>
#include <QDebug>
#include <algorithm>
using namespace std;

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

void Room::sendPlayersInfo() {
    sendAll(sendConv(playersInfo(), "P"));
}

string Room::playersInfo() {
    string data = "";
    for (Player player : players) {
        data += player.name +"-"+to_string(player.score)+"-"+player.avatar + "*";
    }
    return data;
}

void Room::run() {
    qDebug() << "running";
    qDebug() << "Mario";

//    sendAll(sendConv("Meooooooooooooooooooooooooooooooooooooo","N"));

    for (int i=0; i<packs.size(); i++) {
        curPackId++;
        qDebug() << QByteArray::fromStdString("Sending " + to_string(curPackId));
        string packQuestion = "Q=" + string(packs.at(i).q)+"\~" + "A=" + string(packs.at(i).a)+"\~"
                            + "B=" + string(packs.at(i).b)+"\~" + "C=" + string(packs.at(i).c)+"\~"
                            "D=" + string(packs.at(i).d)+"\~";
        sendData = sendConv(packQuestion,"Q");
        emitSendSignal();
//        while (!isSent) {

//        }
//        isSent = true;
    }

    exec();

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

void Room::updateScores() {
    qDebug() << "============updateScores=============";
    string res;

    sort( players.begin(), players.end(), []( Player a, Player b ){ return a.score < b.score;});

    for (Player player : players) {
        res += to_string(player.score) + "-";
    }

    sendAll(sendConv(res, "U"));
}

void Room::emitSendSignal() {
    qDebug() << "vo dc emit signal";
    emit sendSignal();
}

