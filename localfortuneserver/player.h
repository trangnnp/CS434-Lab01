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
    char* name;
    int score = 0;
    QTcpSocket *clientSocket;
};

#endif // PLAYER_H
