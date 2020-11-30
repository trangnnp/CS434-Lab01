#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

#include "pack.h"
#include "singletondata.h"
#include <QObject>
#include <QTimer>
#include <iostream>
#include <ctime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QObject
{
    Q_OBJECT
public:
    explicit MainWindow(QObject *parent = 0);
    ~MainWindow();
    Q_INVOKABLE void printMessage(QString txt);
    Q_INVOKABLE void createMe(QString name);
    Q_INVOKABLE void sendAnswer(int answer);
    Q_INVOKABLE void skipThisTurn();
    Q_PROPERTY(QString packq READ getQ NOTIFY curPackChanged);
    Q_PROPERTY(QString packa READ getA NOTIFY curPackChanged);
    Q_PROPERTY(QString packb READ getB NOTIFY curPackChanged);
    Q_PROPERTY(QString packc READ getC NOTIFY curPackChanged);
    Q_PROPERTY(QString packd READ getD NOTIFY curPackChanged);

    Q_PROPERTY(int aResult MEMBER aResult NOTIFY resultUpdated);
    Q_PROPERTY(int bResult MEMBER bResult NOTIFY resultUpdated);
    Q_PROPERTY(int cResult MEMBER cResult NOTIFY resultUpdated);
    Q_PROPERTY(int dResult MEMBER dResult NOTIFY resultUpdated);
    Q_PROPERTY(int kotae MEMBER kotae NOTIFY resultUpdated);

    Q_PROPERTY(int skipped MEMBER skipped NOTIFY playerInfoUpdated);
    Q_PROPERTY(int playerStatus MEMBER playerStatus NOTIFY playerInfoUpdated);
    Q_PROPERTY(int totalQuestion MEMBER totalQuestion NOTIFY initRoom);
    Q_PROPERTY(int totalPlayer MEMBER totalPlayer NOTIFY initRoom);
    Q_PROPERTY(QString roomName MEMBER roomName NOTIFY initRoom);
    Q_PROPERTY(int timeLimited MEMBER timeLimited NOTIFY initRoom);

    Q_PROPERTY(int packTimerValue MEMBER packTimerValue NOTIFY packTimerTrigged);

public slots:
    void onReadyRead();

signals:
    void curPackChanged();
    void resultUpdated();
    void playerInfoUpdated();
    void initRoom();
    void packTimerTrigged();

private:
    Ui::MainWindow *ui;
    QTcpSocket  _socket;
//    QObject *object;
//    =component.create();
//    void createMe(string name);
    void onGame();
    void splitQ(const string& str);
    void checkAnwer(int correct);
    QByteArray sendConv(string data, string tag);
    void updatePlayerInfo(string data);
    void addNewMsg(string data);
    void updatepackTimerValue();
    void endGame();
    void extractRoomInfo(string data);
    string getTime();
    void popup(QVariant msg);
    QString myName;
    void sleep(float seconds);

    int packTimerValue=0;
    QTimer *timerTurn = new QTimer(this);

    int playerStatus=0;
    int playerId=0;
    int skipped=0;
    int totalQuestion=0;
    int totalPlayer=0;
    int timeLimited=0;
    QString roomName="Name";

    void splitConbinedCmd(vector<string>& res, const string& str, string delims);
    QString getQ() const{ return curPack.q; }
    QString getA() const{ return curPack.a; }
    QString getB() const{ return curPack.b; }
    QString getC() const{ return curPack.c; }
    QString getD() const{ return curPack.d; }

    int getPlayerStatus() const{ return playerStatus; }

//    int getAResult() const{ return curPack.aResult; }

//    void setAResult(int value) { curPack.aResult=value; resultUpdated();}

    int aResult=3;
    int bResult=3;
    int cResult=3;
    int dResult=3;
    int kotae=-1;

    Pack curPack = Pack();
    SingletonClass *singletonData = SingletonClass::Instance();

};

#endif // MAINWINDOW_H
