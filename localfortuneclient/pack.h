#ifndef PACK_H
#define PACK_H

#include<string>
#include<string.h>
#include<iostream>
#include<thread>
#include <QString>

using namespace std;

class Pack
{
private:
    int timer = 5;
    clock_t counter;
public:
    Pack();
//    Pack(char* q, char* a, char* b, char* c, char* d, int correct);
    QString q;
    QString a;
    QString b;
    QString c;
    QString d;

    int aResult = 3;
    int bResult = 3;
    int cResult = 3;
    int dResult = 3;

    int correct = -1;

    void onGame();
};

#endif // PACK_H
