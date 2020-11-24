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
    Q_PROPERTY(QString packq READ getQ NOTIFY curPackChanged);
    Q_PROPERTY(QString packa READ getA NOTIFY curPackChanged);
    Q_PROPERTY(QString packb READ getB NOTIFY curPackChanged);
    Q_PROPERTY(QString packc READ getC NOTIFY curPackChanged);
    Q_PROPERTY(QString packd READ getD NOTIFY curPackChanged);

public:
//    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onReadyRead();

private slots:
    void on_pushButton_clicked();
signals:
    void curPackChanged();

private:
    Ui::MainWindow *ui;
    QTcpSocket  _socket;
//    void createMe(string name);
    void onGame();
    void splitQ(const string& str);
    QByteArray sendConv(string data, string tag);
    void sendAnswer(int answer);
    QString getQ() const{ return curPack.q; }
    QString getA() const{ return curPack.a; }
    QString getB() const{ return curPack.b; }
    QString getC() const{ return curPack.c; }
    QString getD() const{ return curPack.d; }
    Pack curPack = Pack();

};

#endif // MAINWINDOW_H
