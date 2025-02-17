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
#include <QObject>
#include <QString>
#include <QTime>
#include <QEventLoop>
#include <QCoreApplication>

using namespace std;

Room::Room(QObject *parent):QThread()
{
//    connect(timerTurn, &QTimer::timeout, this, &Room::updatepackTimerValue);
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
    QByteArray data = sendConv(playersInfo(), "P");
    qDebug() << data;
    sendAll(data);
}

string Room::playersInfo() {
    string data = "";
    for (Player player : players) {
        data += player.name + "-"+to_string(player.score)+"-"+player.avatar + "-"+ to_string(player.status) + "-"+ to_string(player.skipped ? 1 : 0) + "*";
    }
    return data;
}

void Room::sendRoomInfo() {
    sendAll(sendConv(roomInfo(), "I"));
}

string Room::roomInfo() {
    string data = "";
    data += name.toStdString() + "-";
    data += to_string(players.size()) + "-";
    data += to_string(packs.size()) + "-";
    data += to_string(timeLimited) + "-";
    return data;
}

void Room::run() {
    curPackId = 0;
    curPlayerId = -1;
    isNext = true;

    qDebug() << "============First turn=============";
    qDebug() << limitPacks;
    qDebug() << maxPlayer;
    qDebug() << timeLimited;
    qDebug() << "============First turn=============";

//    QTimer *timerTurn = new QTimer(this);
//    connect(timerTurn, &QTimer::timeout, this, &Room::updatepackTimerValue);


    while (isOnProcess) {
        if (isOnGame) {
            if (isNext) {
                qDebug() << "============next turn=============";
                if (curPackId == packs.size() - 1) {
                    isOnGame = false;
                    qDebug() << "============end game=============";
                    continue;
                }

                if (packs.at(curPackId).answered) {
                    curPackId++;
                }

                qDebug() << curPackId;

                if (curPackId == limitPacks) {
                    isOnGame = false;
                    qDebug() << "============end game 1=============";
                    continue;
                }

                if (curPlayerId != -1) {
                    if (players.at(curPlayerId).status != 2) {
                        players.at(curPlayerId).status = 0;
                    }

                    curPlayerId == (players.size() - 1) ? curPlayerId = 0 : curPlayerId++;

                    while (players.at(curPlayerId).status == 2) {
                        curPlayerId == (players.size() - 1) ? curPlayerId = 0 : curPlayerId++;
                    }
                } else {
                    curPlayerId = 0;
                }

                players.at(curPlayerId).status = 1;
                qDebug() << "============player id=============";
                qDebug() << curPlayerId;

                packQuestion = "Q=" + string(packs.at(curPackId).q)+"\~" + "A=" + string(packs.at(curPackId).a)+"\~"
                                    + "B=" + string(packs.at(curPackId).b)+"\~" + "C=" + string(packs.at(curPackId).c)+"\~"
                                    + "D=" + string(packs.at(curPackId).d)+"\~" + "I=" + to_string(curPackId);

                packq = QByteArray::fromStdString(packs.at(curPackId).q);
                packa = QByteArray::fromStdString(packs.at(curPackId).a);
                packb = QByteArray::fromStdString(packs.at(curPackId).b);
                packc = QByteArray::fromStdString(packs.at(curPackId).c);
                packd = QByteArray::fromStdString(packs.at(curPackId).d);
                kotae = packs.at(curPackId).correct;
                sendData = sendConv(packQuestion,"Q");

    //            timerTurn->start(2000);
//                sendPlayersInfo();
                emitSendInfoSignal();
                qDebug() << "============meoooooooo=============";

                emitSendSignal();
                isNext = false;
            }
        }
    }

    exec();
}

void Room::updateScores() {
    qDebug() << "============updateScores=============";
    string res;

    sort(players.begin(), players.end(), []( Player &a, Player &b ){ return a.score > b.score;});

    for (Player player : players) {
        res += to_string(player.score) + "-";
    }

    sendAll(sendConv(res, "U"));
}

void Room::emitSendSignal() {
    QTime dieTime= QTime::currentTime().addSecs(5);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    qDebug() << "vo dc emit signal";
    emit sendSignal();
}

void Room::emitSendInfoSignal() {
    qDebug() << "vo dc emit info signal";
    emit sendInfoSignal();
}

