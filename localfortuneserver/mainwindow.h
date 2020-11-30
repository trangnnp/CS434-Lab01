#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <vector>
#include <chrono>
#include <thread>
#include "player.h"
#include "packbank.h"
#include "room.h"
#include "singletondata.h"
#include <QTimer>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QObject
{
    Q_OBJECT

public:
    explicit MainWindow(QObject *parent = 0);
    ~MainWindow();

    Q_INVOKABLE void createRoom();
    Q_INVOKABLE void resetRoom();

    Q_PROPERTY(QString packq MEMBER packq NOTIFY onCurPackChanged);
    Q_PROPERTY(QString packa MEMBER packa NOTIFY onCurPackChanged);
    Q_PROPERTY(QString packb MEMBER packb NOTIFY onCurPackChanged);
    Q_PROPERTY(QString packc MEMBER packc NOTIFY onCurPackChanged);
    Q_PROPERTY(QString packd MEMBER packd NOTIFY onCurPackChanged);
    Q_PROPERTY(int correct MEMBER correct NOTIFY onCurPackChanged);

    Q_PROPERTY(int startStatus MEMBER startStatus NOTIFY onStartStatusChanged);

signals:
    void resultUpdated();
    void playerInfoUpdated();
    void initRoom();
    void onCurPackChanged();
    void onStartStatusChanged();

public slots:
    void onNewConnection();
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);
    void onReadyRead();
    void sendData();
    void updatePack();

private:
    Ui::MainWindow *ui;
    QTcpServer  _server;
    QList<QTcpSocket*>  _sockets;
    PackBank packBank = PackBank();
    bool isOnGame = false;
    Room *room = new Room();
    void getPacksForRoom(Room *room);
    void onGame();
    void updatepackTimerValue();
    QByteArray sendConv(string data, string tag);
    void addNewPlayer(string name, QTcpSocket* socket);
    void collectAnswer(int answer, QTcpSocket* socket);
    void sendCorrectAnswer();
    void updatePlayerInfo();
    void endGame();
    string getSenderFromConnection(QTcpSocket *connection);
    void addNewMsg(string data, string sender);
    string getTime();

    int countActive;
    QTimer *timerTurn = new QTimer(this);

    string colors[10] = {"fb8f67", "ffc2b4", "f8e16c", "00c49a", "156064", "f2b5d4", "8980f5", "ff70a6", "ffc462", "d0e3cc"};

    SingletonClass *singletonData = SingletonClass::Instance();

    QString packq;
    QString packa;
    QString packb;
    QString packc;
    QString packd;
    int correct=-1;

    int startStatus = 0; // 0: not able to start  1: able   3: restart    2: ongame
};

#endif // MAINWINDOW_H
