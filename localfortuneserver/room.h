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

#ifndef ROOM_H
#define ROOM_H
#include "player.h"
#include "pack.h"
#include <QThread>
#include <QObject>

class Room: public QThread
{
    Q_OBJECT
public:
    Room(QObject *parent = 0);
    QString name = "Camel";
    int limitPacks = 5;
    int timeLimited = 10;
    int maxPacks = 30;
    vector<Player> players;
    vector<Pack> packs;
    int curPackId = -1;
    int curPlayerId=0;
    int maxPlayer = 2;
    void run() override;
    void sendAll(QByteArray dataSend);
    void sendPlayersInfo();
    void sendRoomInfo();
    string playersInfo();
    string roomInfo();
    int scorePerPack=1000;
    bool isOnGame=false;
    void updateScores();
    bool isNext=false;
    QByteArray sendData;
    void emitSendSignal();

    Q_PROPERTY(int totalQuestion MEMBER limitPacks NOTIFY initRoom);
    Q_PROPERTY(int totalPlayer MEMBER maxPlayer NOTIFY initRoom);
    Q_PROPERTY(QString roomName MEMBER name NOTIFY initRoom);
    Q_PROPERTY(int timeLimited MEMBER timeLimited NOTIFY initRoom);

    QString packq = "aaaaaaaaaaaa";
    QString packa;
    QString packb;
    QString packc;
    QString packd;
    int kotae=-1;

signals:
    void sendSignal();
    void answerSignal();
    void curPackChanged();
    void initRoom();


private:

};

#endif // ROOM_H
