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
    int stauts = 0;
    int score = 0;
    QTcpSocket *clientSocket;
};

#endif // PLAYER_H
