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

#include "playerlist.h"
#include "playermodel.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<MainWindow>("MainWindow", 1, 0, "MainWindow");
    qmlRegisterType<PlayerModel>("PlayerModel", 1, 0, "PlayerModel");
    qmlRegisterUncreatableType<PlayerList>("PlayerList", 1, 0, "PlayerList",
        QStringLiteral("playerList should not be created in QML"));

    PlayerList playerList;
    Player item = Player();
    item.name = "Meo1";
    item.score=10000;
    item.avatar="#f4a261";
    playerList.appendItem(item);

    item.name = "Meo2";
    item.score=20000;
    item.avatar="pink";
    playerList.appendItem(item);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("playerList"), &playerList);
    engine.load(QUrl(QLatin1String("qrc:/Layout.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
