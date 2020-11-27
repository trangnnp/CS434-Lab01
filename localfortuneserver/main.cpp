#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QMetaObject>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<MainWindow>("MainWindow", 1, 0, "MainWindow");

    QQmlEngine engine;
    QQmlComponent component(&engine, "qrc:/Layout.qml");
    QObject *object = component.create();

    return app.exec();
}
