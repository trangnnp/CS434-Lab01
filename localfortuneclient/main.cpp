/*
 *   Copyright (c) 2020 Trang Ngoc-Phuong Nguyen
 *   All rights reserved.

 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at

 *   http://www.apache.org/licenses/LICENSE-2.0

 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QMetaObject>
#include "playerlist.h"
#include "msglist.h"

#include "playermodel.h"
#include "msgmodel.h"

#include "mainwindow.h"
#include "singletondata.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    SingletonClass *t = SingletonClass::Instance();

    qmlRegisterType<MainWindow>("MainWindow", 1, 0, "MainWindow");
    qmlRegisterType<PlayerModel>("PlayerModel", 1, 0, "PlayerModel");
    qmlRegisterType<MsgModel>("MsgModel", 1, 0, "MsgModel");

    qmlRegisterUncreatableType<PlayerList>("PlayerList", 1, 0, "PlayerList",
        QStringLiteral("playerList should not be created in QML"));

    qmlRegisterUncreatableType<MsgList>("MsgList", 1, 0, "MsgList",
        QStringLiteral("MsgList should not be created in QML"));

    QQmlEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("msgList"), &t->msgList);
    engine.rootContext()->setContextProperty(QStringLiteral("playerList"), &t->playerList);

    QQmlComponent component(&engine, "qrc:/Layout.qml");
    QObject *object = component.create();


    QVariant returnedValue;
    QVariant msg = "Hello from C++";

    QMetaObject::invokeMethod(object, "myQmlFunction",
        Q_RETURN_ARG(QVariant, returnedValue),
        Q_ARG(QVariant, msg));

    qDebug() << "QML function returned:" << returnedValue.toString();


    return app.exec();
}
