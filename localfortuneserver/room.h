#ifndef ROOM_H
#define ROOM_H
#include "player.h"
#include "pack.h"

class Room
{
public:
    Room();
    char* name;
    int limitPacks = 5;
    int maxPacks = 5;
    vector<Player> players;
    vector<Pack> packs;
    int curPackId = -1;
};

#endif // ROOM_H
