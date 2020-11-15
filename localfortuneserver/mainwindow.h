#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <vector>
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
private:
    Ui::MainWindow *ui;
    QTcpServer  _server;
    QList<QTcpSocket*>  _sockets;
    vector<Player> players;
    PackBank packBank = PackBank();
    bool isOnGame = false;
    Room room = Room();
    void getPacksForRoom(Room *room);
    void onGame();
};

#endif // MAINWINDOW_H
