#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

#include "pack.h"
#include <QObject>


namespace Ui {
class MainWindow;
}

class MainWindow : public QObject
{
    Q_OBJECT
    public:
    explicit MainWindow(QObject *parent = 0);
    Q_INVOKABLE void printMessage(QString txt);
    Q_INVOKABLE void createMe(QString name);


public:
//    explicit MainWindow(QWidget *parent = 0);
//    ~MainWindow();

public slots:
    void onReadyRead();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket  _socket;
    Pack curPack = Pack();
//    void createMe(string name);
    void onGame();
    QByteArray sendConv(string data, string tag);
    void sendAnswer(int answer);
};

#endif // MAINWINDOW_H
