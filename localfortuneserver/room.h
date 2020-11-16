#ifndef ROOM_H
#define ROOM_H
#include "player.h"
#include "pack.h"

class Room
{
public:
    Room();
    char* name;
    int limitPacks = 1;
    int maxPacks = 30;
    vector<Player> players;
    vector<Pack> packs;
    int curPackId = -1;
};

#endif // ROOM_H
