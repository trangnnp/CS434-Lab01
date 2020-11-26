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
    int maxPlayer = 1;
    void run() override;
    void sendAll(QByteArray dataSend);
    void sendPlayersInfo();
    string playersInfo();
    int scorePerPack=1000;
    bool isOnGame=false;
    void updateScores();
    bool cmp(const Player *a, const Player *b);
};

#endif // ROOM_H
