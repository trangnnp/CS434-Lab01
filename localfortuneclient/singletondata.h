#ifndef TESTT_H
#define TESTT_H
#include "playerlist.h"
#include "msglist.h"

class SingletonClass
{
    public:
        static SingletonClass* Instance()
        {
           static SingletonClass* instance = new SingletonClass();
           return instance;
        }

        PlayerList playerList;
        MsgList msgList;


    private:
        SingletonClass();
        ~SingletonClass();
};


#endif // TESTT_H



