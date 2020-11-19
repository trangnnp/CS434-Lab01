#ifndef PACK_H
#define PACK_H

#include<string>
#include<string.h>
#include<iostream>
#include<thread>

using namespace std;

class Pack
{
private:
    int timer = 5;
    clock_t counter;
public:
    Pack();
//    Pack(char* q, char* a, char* b, char* c, char* d, int correct);
    string q;
    string a;
    string b;
    string c;
    string d;
    int correct = -1;

    void onGame();
};

#endif // PACK_H
