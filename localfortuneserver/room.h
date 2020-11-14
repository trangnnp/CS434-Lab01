#ifndef ROOM_H
#define ROOM_H
#include "player.h"
#include "pack.h"

class Room
{
public:
    Room();
    char* name;
    vector<Player> players;
    vector<Pack> packs;
    int curPackId = -1;
};

#endif // ROOM_H
