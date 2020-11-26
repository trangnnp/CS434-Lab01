#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

#include "pack.h"
#include "singletondata.h"
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
    Q_INVOKABLE void sendAnswer(int answer);
    Q_PROPERTY(QString packq READ getQ NOTIFY curPackChanged);
    Q_PROPERTY(QString packa READ getA NOTIFY curPackChanged);
    Q_PROPERTY(QString packb READ getB NOTIFY curPackChanged);
    Q_PROPERTY(QString packc READ getC NOTIFY curPackChanged);
    Q_PROPERTY(QString packd READ getD NOTIFY curPackChanged);

//    Q_PROPERTY(int aResult READ getAResult WRIRTE setAResult NOTIFY resultUpdated);
    Q_PROPERTY(int aResult MEMBER aResult NOTIFY resultUpdated);
    Q_PROPERTY(int bResult MEMBER bResult NOTIFY resultUpdated);
    Q_PROPERTY(int cResult MEMBER cResult NOTIFY resultUpdated);
    Q_PROPERTY(int dResult MEMBER dResult NOTIFY resultUpdated);

public:
//    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onReadyRead();

private slots:
    void on_pushButton_clicked();
signals:
    void curPackChanged();
    void resultUpdated();

private:
    Ui::MainWindow *ui;
    QTcpSocket  _socket;
//    void createMe(string name);
    void onGame();
    void splitQ(const string& str);
    void checkAnwer(int correct);
    QByteArray sendConv(string data, string tag);
    void updatePlayerInfo(string data);
    void addNewMsg(string data);
    string getTime();
    void splitConbinedCmd(vector<string>& res, const string& str, string delims);
    QString getQ() const{ return curPack.q; }
    QString getA() const{ return curPack.a; }
    QString getB() const{ return curPack.b; }
    QString getC() const{ return curPack.c; }
    QString getD() const{ return curPack.d; }

//    int getAResult() const{ return curPack.aResult; }

//    void setAResult(int value) { curPack.aResult=value; resultUpdated();}

    int aResult=3;
    int bResult=3;
    int cResult=3;
    int dResult=3;

    Pack curPack = Pack();
    SingletonClass *singletonData = SingletonClass::Instance();

};

#endif // MAINWINDOW_H
