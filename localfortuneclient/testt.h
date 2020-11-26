#ifndef TESTT_H
#define TESTT_H
#include "playerlist.h"

class SingletonClass
{
    public:
        static SingletonClass* Instance()
        {
           static SingletonClass* instance = new SingletonClass();
           return instance;
        }

        void Relocate(int X, int Y, int Z);
        PlayerList playerList;

    private:
        SingletonClass();
        ~SingletonClass();
};


#endif // TESTT_H



