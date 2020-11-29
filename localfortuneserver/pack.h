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
    Pack(string q, string a, string b, string c, string d, int correct);
    string q;
    string a;
    string b;
    string c;
    string d;
    int correct;
    bool answered = false;
};

#endif // PACK_H
