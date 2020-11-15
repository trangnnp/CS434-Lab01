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
//    Pack(char* q, char* a, char* b, char* c, char* d, int correct);
    string q;
    string a;
    string b;
    string c;
    string d;
    int correct = -1;
};

#endif // PACK_H
