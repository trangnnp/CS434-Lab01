#ifndef PLAYER_H
#define PLAYER_H

#include <QTcpSocket>
#include<string>
#include<string.h>

using namespace std;
class Player
{
public:
    Player();
    int id;
    string name;
    int status = 0;
    //    0: waiting, not in turn
    //    1: start, in turn
    //    2: sayonara
    //    3: isWinner
    //    4: NotBeWinner
    bool skipped=false;
    int score = 0;
    string avatar = "white";
    QTcpSocket *clientSocket;
};

#endif // PLAYER_H
