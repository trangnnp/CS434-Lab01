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
    Room();
    char* name;
    int limitPacks = 2;
    int maxPacks = 30;
    vector<Player> players;
    vector<Pack> packs;
    int curPackId = -1;
    void run();
    void sendAll(QByteArray dataSend);
    bool isOnGame=false;
    bool isSent=false;
    QByteArray sendData;

    void updateScores();

    void emitSendSignal();
signals:
    void sendSignal();
};

#endif // ROOM_H
