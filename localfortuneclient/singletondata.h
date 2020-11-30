#ifndef TESTT_H
#define TESTT_H
#include "playerlist.h"
#include "msglist.h"
#include <QQmlEngine>
#include <QObject>
#include <QQmlComponent>

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
        QQmlEngine engine;
        QQmlComponent *component;
        QObject *object;


    private:
        SingletonClass();
        ~SingletonClass();
};


#endif // TESTT_H



