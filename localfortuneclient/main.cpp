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
#include <QQmlComponent>
//#import QtQml.Models 2.15

int main(int argc, char *argv[])
{
    qmlRegisterType<MainWindow>("MainWindow", 1, 0, "MainWindow");
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine(":/Layout.qml");

//    QQmlEngine engine;
//    QQmlComponent component(&engine, ":/Layout.qml");
    QObject *object = engine.rootObjects().first();

    //                    ListElement { name: 'Meo1'; code: "12.000.000"; language: "english" }


//    QListElement dataList;
//    dataList.append("Item 1");
//    dataList.append("Item 2");
//    dataList.append("Item 3");
//    dataList.append("Item 4");

//    QQuickView view;
//    QQmlContext *ctxt = view.rootContext();
//    ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));

    return app.exec();
}


