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

using namespace std;

namespace Ui {
class MainWindow;
}

//connect guest - server: room names + username

//                        split buffer in client
//                        reconignize tags
//                        add data to client pack

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onNewConnection();
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);
    void onReadyRead();
    void sendData();
private:
    Ui::MainWindow *ui;
    QTcpServer  _server;
    QList<QTcpSocket*>  _sockets;
    PackBank packBank = PackBank();
    bool isOnGame = false;
    Room *room = new Room();
    void getPacksForRoom(Room *room);
    void onGame();
    QByteArray sendConv(string data, string tag);
    void addNewPlayer(string name, QTcpSocket* socket);
    void collectAnswer(int answer, QTcpSocket* socket);
    void sendCorrectAnswer();
    string colors[5] = {"yellow", "blue", "green", "gray", "pink"};
};

#endif // MAINWINDOW_H
