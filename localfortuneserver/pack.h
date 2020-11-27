#ifndef PACK_H
#define PACK_H

#include<string>
#include<string.h>
#include<iostream>

using namespace std;

class Pack
{
public:
    Pack();
    Pack(char* q, char* a, char* b, char* c, char* d, int correct);
    char* q;
    char* a;
    char* b;
    char* c;
    char* d;
    int correct;
    bool answered = false;
};

#endif // PACK_H
