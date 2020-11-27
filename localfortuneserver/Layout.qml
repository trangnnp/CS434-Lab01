import QtQuick 2.15
//import "../shared" as Examples
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQml.Models 2.15
import QtQuick.Controls.Styles 1.4
import QtQuick 2.0
import QtQuick.Controls 1.4

import MainWindow 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 1200
    height: 680

    MainWindow {
        id: server
    }

    Image {
        id: background
        Layout.fillWidth: true
        Layout.fillHeight: true
        anchors.fill: parent
        source: "qrc:/shared/2_75.png"

        Image {
            id: logo
            source: "qrc:/shared/logo.png"
            x: background.paintedWidth*0.444
            y: background.paintedHeight*0.134
            width: background.paintedHeight*0.23
            height: logo.width
        }
    }

}
