#ifndef ROOM_H
#define ROOM_H
#include "player.h"
#include "pack.h"
#include <QThread>

class Room: public QThread
{
public:
    Room();
    char* name;
    int limitPacks = 2;
    int maxPacks = 30;
    vector<Player> players;
    vector<Pack> packs;
    int curPackId = -1;
    int maxPlayer = 2;
    void run() override;
    void sendAll(QByteArray dataSend);
    void sendPlayersInfo();
    string playersInfo();
    bool isOnGame=false;
    void updateScores();
};

#endif // ROOM_H
