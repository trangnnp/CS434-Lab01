#ifndef TESTT_H
#define TESTT_H
#include "msglist.h"
#include "playerlist.h"

class SingletonClass
{
    public:
        static SingletonClass* Instance()
        {
           static SingletonClass* instance = new SingletonClass();
           return instance;
        }

        MsgList msgList;
        PlayerList playerList;


    private:
        SingletonClass();
        ~SingletonClass();
};


#endif // TESTT_H



