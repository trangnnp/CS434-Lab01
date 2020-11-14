#ifndef PACKBANK_H
#define PACKBANK_H

#include "pack.h"
#include<vector>
using namespace std;

class PackBank
{
public:
    PackBank();

    vector<Pack> packs;
    int total=0;
    vector<int*> prevIds;
    void initPacks();
    void getPacksByIds(vector<Pack> *packs);
};

#endif // PACKBANK_H
