//#include "mainwindow.h"
//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
//}


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<MainWindow>("MainWindow", 1, 0, "MainWindow");
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine(":/Layout.qml");
    return app.exec();
}
