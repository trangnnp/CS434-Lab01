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
import Room 1.0
import PlayerModel 1.0
import MsgModel 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 1200
    height: 680

    property var choosen: "#f4a261"
    property var correctans: "#e76f51"
//    property var normal: "#eec1a2"
    property var normal: "#003494"

    property var wrongans: "#354f52"
    property var correct: "#81b29a"

    property var packColor: "#003494"
    property var boderColor: "#fff0ad"
    property var textColor: "white"
    property var prefixColor: "<b> <font color=\"#ffea00\">A:</font> <font color=\"#ffea00\"></font><b>"

    property var statusWaitingColor: "white"
    property var statusNotInTurnColor: "#e5e5e5"
    property var statusInTurnColor: "#fca311"
    property var statusDieColor: "#e5e5e5"
    property var msg: ""

    MainWindow {
        id: server
    }

    Room {
        id: room
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

    Rectangle   {
        id: settingLayout
        x: background.paintedWidth*0.4
        y: background.paintedHeight*0.5
        width: background.paintedHeight*0.4
        color: "yellow"

        Frame {
            Column {
                anchors.fill: parent
                spacing: 10

                Row {
                    spacing: 10
                    Label { text: '<b>' + "Room name: " + '</b>'; color: textColor;}
                    TextField {
                        text: room.roomName
                        onTextChanged: room.roomName = text
                    }
                }

                Row {
                    spacing: 10
                    Label { text: '<b>' + "Total Question: " + '</b>'; color: textColor;}
                    TextField {
                        text: room.totalQuestion
                        onTextChanged: room.totalQuestion = text
                    }
                }

                Row {
                    spacing: 10
                    Label { text: '<b>' + "Total Player: " + '</b>'; color: textColor;}
                    TextField {
                        text: room.totalPlayer
                        onTextChanged: room.totalPlayer = text
                    }
                }

                Row {
                    spacing: 10
                    Label { text: '<b>' + "Time per Question: " + '</b>'; color: textColor;}
                    TextField {
                        text: room.timeLimited
                        onTextChanged: room.timeLimited = text
                    }
                }

                Button {
                    text: "Create room"
                    width: settingLayout.width
                    onClicked: {
                        settingLayout.visible = false
                        onGameLayout.visible = true
                        room.initRoom();
                        server.createRoom()
                    }
                }
            }
        }
    }

    GridLayout {
        id: onGameLayout
        visible: false
        anchors.fill: parent
        rowSpacing: 20
        columnSpacing: 0
        flow:  width > height ? GridLayout.LeftToRight : GridLayout.TopToBottom
        Rectangle {
            id: mainOnGameLayout
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#1e1b18"
            Layout.preferredWidth: 3
            Label {
                anchors.centerIn: parent
                color: "#443224"
            }

            Image {
                id: background1
                Layout.fillWidth: true
                Layout.fillHeight: true
                anchors.fill: parent
                source: "qrc:/shared/2_75.png"

                PathView {
                    id: pathView

                    width: image.paintedHeight*0.3
                    height: width
                    x: 40
                    y: image.paintedHeight - 2*image.viewSize - 2*image.recSize

                    model: PlayerModel {
                        list: playerList
                    }
                    delegate: Rectangle {
                        width: image.recSize
                        height: width
                        radius: 10
                        color: "#" + avatar
                        Text {
                            text: "<b> " + name + "<b>"
                            anchors.centerIn: parent
                            color:  status == 0 ? statusNotInTurnColor : status == 1 ? statusInTurnColor : statusDieColor
                            transform: [
                                Translate {y: -30}
                            ]
                        }
                    }
                    path: Path {
                        id: myPath
                        startX: 0; startY: 0
                        PathSvg { path: "M " + image.viewSize + " " + image.viewSize + " m -" + image.viewSize + " 0 a " + image.viewSize + " " + image.viewSize + " 0 1 0 " + 2*image.viewSize + " 0 a " + image.viewSize + " " + image.viewSize + " 0 1 0 -" + 2*image.viewSize + " 0" }
                    }
                }
                Image {
                    id: logo1
                    source: "qrc:/shared/logo.png"
                    x: background1.paintedWidth*0.444
                    y: background1.paintedHeight*0.134
                    width: background1.paintedHeight*0.23
                    height: logo.width
                }
            }

            ColumnLayout {
                visible: true
                anchors.fill: parent
                spacing: 0

                Image {
                    id: image
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredHeight: 3

                    property real lineWidthx: 5
                    property real recSize: 20
                    property real viewSize: 100

                    Rectangle {
                        id: start
                        width: image.paintedHeight*0.25
                        height: start.width / 2
                        x: image.paintedWidth - width
                        y: image.paintedHeight - height
                        radius: 5
                        color: server.startStatus === 0 ? "grey" : server.startStatus === 1 ? "#90be6d" : server.startStatus ===2 ? "#3d405b" : "#ff6b6b"
                        Label {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: server.startStatus === 0 ? "waiting" : server.startStatus === 1 ? "Start Game" : server.startStatus ===2 ? "On game" : "Reset Game"
                            color: "white"
                            font.pixelSize: 18
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                server.resetRoom();
                            }
                        }
                    }

                    Frame {
                        id: frame
                        x: image.paintedWidth*0.03
                        y: image.paintedHeight*0.1

                        property var textSize: 14

                        Column {

                            spacing: 5
                            Text {
                                text: '<b> Room Name: </b> ' + room.roomName
                                font.family: "Helvetica"; font.pointSize: frame.textSize; color: textColor
                            }
                            Text {
                                text: '<b> Num. of Players: </b> ' + room.totalPlayer
                                font.family: "Helvetica"; font.pointSize: frame.textSize; color: textColor
                            }
                            Text {
                                text: '<b> Num. of Questions: </b>' + room.totalQuestion
                                font.family: "Helvetica"; font.pointSize: frame.textSize; color: textColor
                            }
                            Text {
                                text: '<b> Time limited: </b>' + room.timeLimited + " seconds"
                                font.family: "Helvetica"; font.pointSize: frame.textSize; color: textColor
                            }
                        }
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredHeight: 1
                    color: "#010103"

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.topMargin: 10
                        anchors.bottomMargin: 30
                        anchors.leftMargin: 40
                        anchors.rightMargin: 40

                        Rectangle {
                            id: packQ
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.preferredHeight: 3
                            color: packColor
                            radius: 20
                            border.color: boderColor
                            border.width: 2
                            Label {
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                                anchors.centerIn: parent
                                wrapMode: Text.WordWrap
                                text: '<b> ' + server.packq + '</b> '
                                color: textColor
                            }
                        }

                        Rectangle {
                            id: packAB
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            anchors.margins: 20
                            Layout.preferredHeight: 2
                            color: "#010103"

                            RowLayout {
                                anchors.fill: parent
                                Rectangle {
                                    id: packA

                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    color:  server.correct === 0? correct : normal
                                    radius: 30
                                    border.color: boderColor
                                    border.width: 2
                                    Label {
                                        anchors.centerIn: parent
                                        text: "<b> <font color=\"#ffea00\">A:</font> <font color=\"#ffea00\"> </font><b>" + server.packa
                                        color: textColor
                                    }
                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            server.kotae = 0
                                        }
                                    }
                                }
                                Rectangle {
                                    id: packB
                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    color:  server.correct === 1? correct : normal
                                    radius: 30
                                    border.color: boderColor
                                    border.width: 2
                                    Label {
                                        anchors.centerIn: parent
                                        text: "<b> <font color=\"#ffea00\">B:</font> <font color=\"#ffea00\"> </font><b>" + server.packb
                                        color: textColor
                                    }
                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            server.kotae = 1
                                        }
                                    }
                                }
                            }
                        }
                        Rectangle {
                            id: packCD
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            anchors.margins: 20
                            Layout.preferredHeight: 2
                            color: "#010103"

                            RowLayout {
                                anchors.fill: parent
                                Rectangle {
                                    id: packC
                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    color:  server.correct === 2? correct : normal
                                    radius: 30
                                    border.color: boderColor
                                    border.width: 2
                                    Label {
                                        anchors.centerIn: parent
                                        text: "<b> <font color=\"#ffea00\">C:</font> <font color=\"#ffea00\"> </font><b>" + server.packc
                                        color: textColor
                                    }
                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            server.kotae = 2
                                        }
                                    }
                                }
                                Rectangle {
                                    id: packD
                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    color:  server.correct === 3? correct : normal
                                    radius: 30
                                    border.color: boderColor
                                    border.width: 2
                                    Label {
                                        anchors.centerIn: parent
                                        text: "<b> <font color=\"#ffea00\">D:</font> <font color=\"#ffea00\"> </font><b>" + server.packd
                                        color: textColor
                                        horizontalAlignment: Text.AlignLeft
                                    }
                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            server.kotae = 3
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        Rectangle {
            id : rankingLayout
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: 1
            anchors.margins: 20

            color: "#010103"

            function formatNumber(data) {
                return data.toString().replace(/(\d)(?=(\d{3})+(?!\d))/g, '$1,')
            }


            ColumnLayout {
                anchors.margins: 10
                anchors.fill: parent

                ListView {
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    orientation: Qt.Vertical
                    Layout.preferredHeight: 5
                    model: PlayerModel {
                        list: playerList
                    }
                    spacing: 10

                    delegate: Component {
                        Row {
                            spacing: 10
                            Rectangle { height: parent.height; width: parent.height; color: "#" + avatar; radius: 10 }
                            Column {
                                Label {
                                    Layout.fillHeight: true
                                    Layout.fillWidth: true
                                    Layout.preferredHeight: implicitHeight
                                    text: '<b> ' + name + '</b> '
                                    color: "pink"
                                }

                                Label {
                                    Layout.fillHeight: true
                                    Layout.fillWidth: true
                                    Layout.preferredHeight: implicitHeight
                                    text: rankingLayout.formatNumber(score)
                                    color: "pink"
                                }
                            }
                        }
                    }
                }

                ListView {
                    id: listview
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredHeight: 3

                    orientation: Qt.Vertical
                    model: MsgModel {
                        list: msgList
                    }
                    spacing: 5

                    delegate: Component {
                        Row {
                            Label {
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                                Layout.preferredHeight: implicitHeight
                                width: listview.width
                                text: "[" + timestamp + "] " + '<b> ' + sender + '</b> ' + ": " + content
                                color: "yellow"
                                wrapMode: Text.WordWrap
                            }
                        }
                    }

                    onCountChanged: {
                        Qt.callLater( listview.positionViewAtEnd )
                    }
                }
            }
        }

        }
}

