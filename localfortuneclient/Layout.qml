/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

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
import PlayerModel 1.0
import MsgModel 1.0


import QtQml 2.2

ApplicationWindow {
    id: root
    visible: true
    width: 1200
    height: 680

    function myQmlFunction(msg) {
          console.log("Got message:", msg)
          return "some return value"
    }

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

    MainWindow {
        id: client
    }

    Image {
        id : welcomePage
        Layout.fillWidth: true
        Layout.fillHeight: true
        source: "qrc:/shared/2_75.png"
        anchors.fill: parent

        property real lineWidthx: 5

        Image {
            id: logo1
            source: "qrc:/shared/logo.png"
            x: welcomePage.paintedWidth*0.444
            y: welcomePage.paintedHeight*0.134
            width: welcomePage.paintedHeight*0.23
            height: logo1.width
        }

        Rectangle {
            id: name_textbox
            width: welcomePage.width*0.4
            height: welcomePage.height*0.3
            color: "white"
            opacity: 0.7
            layer.enabled: true
            x: welcomePage.width*0.52 - width/2
            y: welcomePage.height*0.5
            Rectangle {
                anchors.centerIn: parent
                height: enter_name.height + input_name.height
                width: enter_name.width + input_name.width
                Label {
                    id: enter_name
                    text: "Enter your name"
                    font.family: font.name
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 25
                    font.bold: true
                    font.capitalization: Font.AllUppercase
                }
                TextField {
                    id: input_name
                    anchors.top: enter_name.bottom
                    anchors.topMargin: 10
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 18

                    function _onEnterPressed(event) {
                        client.createMe(input_name.text)
                        welcomePage.visible = false
                        onGameLayout.visible = true
                    }

                    Keys.onReturnPressed: { _onEnterPressed(event) }
                    Keys.onEnterPressed: { _onEnterPressed(event) }
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

            ColumnLayout {
                visible: true
                anchors.fill: parent
                spacing: 0

                Image {
                    id: image
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredHeight: 3
                    source: "qrc:/shared/2_75.png"
                    property real lineWidthx: 5

                    PathView {
                        id: pathView
                        width: image.paintedHeight*0.3
                        height: width
                        x: 40
                        y: image.paintedHeight*0.3

                        property real recSize: 20
                        property real viewSize: 200

                        model: PlayerModel {
                            list: playerList
                        }
                        delegate: Rectangle {
                            width: parent.recSize
                            height: width
                            radius: 10
                            color: avatar
                            Text {
                                text: "<b> " + name + "<b>"
                                anchors.centerIn: parent
                                color:  status == 0 ? statusNotInTurnColor : status == 1 ? statusInTurnColor : status == 2 ? statusDieColor : statusWaitingColor
                                transform: [
                                    Translate {y: -30}
                                ]
                            }
                        }
                        path: Path {
                            id: myPath
                            startX: 0; startY: 0
                            PathSvg { path: "M " + pathView.viewSize + " " + pathView.viewSize + " m -" + pathView.viewSize + " 0 a " + pathView.viewSize + " " + pathView.viewSize + " 0 1 0 " + pathView.viewSize + " 0 a " + pathView.viewSize + " " + pathView.viewSize + " 0 1 0 -" + pathView.viewSize + " 0" }
                        }
                    }

                    Image {
                        id: logo
                        source: "qrc:/shared/logo.png"
                        x: image.paintedWidth*0.444
                        y: image.paintedHeight*0.134
                        width: image.paintedHeight*0.23
                        height: logo.width
                    }

                    Item {
                        id: packTimer
                        x: image.paintedWidth*0.444-image.lineWidthx*2
                        y: image.paintedHeight*0.134-image.lineWidthx*2
                        Canvas {
                            id: canvas
                            width: image.paintedHeight*0.23 + image.lineWidthx*4
                            height: canvas.width
                            antialiasing: true

                            property color primaryColor: "gray"
                            property color secondaryColor: "#ff36ab"

                            property real lineWidth: image.lineWidthx
                            property real centerWidth: width / 2
                            property real centerHeight: height / 2
                            property real radius: Math.min(canvas.width, canvas.height) / 2 - lineWidth/2

                            property real minimumValue: 0
                            property real maximumValue: client.timeLimited*1000
                            property real currentValue: 0


                            // this is the angle that splits the circle in two arcs
                            // first arc is drawn from 0 radians to angle radians
                            // second arc is angle radians to 2*PI radians
                            property real angle: (currentValue - minimumValue) / (maximumValue - minimumValue) * 2 * Math.PI

                            // we want both circle to start / end at 12 o'clock
                            // without this offset we would start / end at 9 o'clock
                            property real angleOffset: -Math.PI / 2

                            property string text: "Text"

                            signal clicked()

                            onPrimaryColorChanged: requestPaint()
                            onSecondaryColorChanged: requestPaint()
                            onMinimumValueChanged: requestPaint()
                            onMaximumValueChanged: requestPaint()
                            onCurrentValueChanged: requestPaint()

                            onPaint: {
                                var ctx = getContext("2d");
                                ctx.save();

                                ctx.clearRect(0, 0, canvas.width, canvas.height);

                                // fills the mouse area when pressed
                                // the fill color is a lighter version of the
                                // secondary color

                                if (mouseArea.pressed) {
                                    ctx.beginPath();
                                    ctx.lineWidth = lineWidth;
                                    ctx.fillStyle = Qt.lighter(canvas.secondaryColor, 1.25);
                                    ctx.arc(canvas.centerWidth,
                                            canvas.centerHeight,
                                            canvas.radius,
                                            0,
                                            2*Math.PI);
                                    ctx.fill();
                                }

                                // First, thinner arc
                                // From angle to 2*PI

                                ctx.beginPath();
                                ctx.lineWidth = lineWidth;
                                ctx.strokeStyle = primaryColor;
                                ctx.arc(canvas.centerWidth,
                                        canvas.centerHeight,
                                        canvas.radius,
                                        angleOffset + canvas.angle,
                                        angleOffset + 2*Math.PI);
                                ctx.stroke();


                                // Second, thicker arc
                                // From 0 to angle

                                ctx.beginPath();
                                ctx.lineWidth = lineWidth;
                                ctx.strokeStyle = canvas.secondaryColor;
                                ctx.arc(canvas.centerWidth,
                                        canvas.centerHeight,
                                        canvas.radius,
                                        canvas.angleOffset,
                                        canvas.angleOffset + canvas.angle);
                                ctx.stroke();

                                ctx.restore();
                                text = currentValue
                            }

//                            Text {
//                                anchors.centerIn: parent
//                                text: canvas.text
//                                color: canvas.primaryColor
//                            }

                            MouseArea {
                                id: mouseArea
                                anchors.fill: parent
                                onClicked: canvas.clicked()
                                onPressedChanged: canvas.requestPaint()
                            }
                        }

                         // Timer to show off the progress bar
                         Timer {
                             id: simpletimer
                             interval: 100
                             repeat: true
                             running: true
                             onTriggered: canvas.currentValue < canvas.maximumValue ? canvas.currentValue += interval: canvas.currentValue = canvas.minimumValue
                         }
                    }

                    Image {
                        id: save
                        source: client.playerStatus == 0 ? "qrc:/shared/save2.png" : "qrc:/shared/save3.png"
                        width: image.paintedHeight*0.25
                        height: save.width
                        x: image.paintedWidth - width - 10
                        y: image.paintedHeight - height - 10
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                client.skipThisTurn();
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
                                text: '<b> Num. of Players: </b> ' + client.totalPlayer
                                font.family: "Helvetica"; font.pointSize: frame.textSize; color: textColor
                            }
                            Text {
                                text: '<b> Num. of Questions: </b>' + client.totalQuestion
                                font.family: "Helvetica"; font.pointSize: frame.textSize; color: textColor
                            }
                            Text {
                                text: '<b> Current Question: </b>' + "<b> <font color=\"#ffea00\">" + client.totalPlayer + "</font> <font color=\"#ffea00\"></font><b>"
                                font.family: "Helvetica"; font.pointSize: frame.textSize; color: textColor
                            }
                            Text {
                                text: '<b> Time limited: </b>' + client.timeLimited + " seconds"
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
                                text: '<b> ' + client.packq + '</b> '
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
                                    color: client.aResult===0 ? choosen : client.aResult===1 ? correct : client.aResult===2 ? correctans : client.aResult ==4 ? wrongans : normal
                                    radius: 30
                                    border.color: boderColor
                                    border.width: 2
                                    Label {
                                        anchors.centerIn: parent
                                        text: "<b> <font color=\"#ffea00\">A:</font> <font color=\"#ffea00\"> </font><b>" + client.packa
                                        color: textColor
                                    }
                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            client.sendAnswer(0)
                                            client.aResult = 0
                                        }
                                    }
                                }
                                Rectangle {
                                    id: packB
                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    color: client.bResult===0 ? choosen : client.bResult===1 ? correct : client.bResult===2 ? correctans : client.bResult ==4 ? wrongans : normal
                                    radius: 30
                                    border.color: boderColor
                                    border.width: 2
                                    Label {
                                        anchors.centerIn: parent
                                        text: "<b> <font color=\"#ffea00\">B:</font> <font color=\"#ffea00\"> </font><b>" + client.packb
                                        color: textColor
                                    }
                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            client.sendAnswer(1)
                                            client.bResult = 0
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
                                    color: client.cResult===0 ? choosen : client.cResult===1 ? correct : client.cResult===2 ? correctans : client.cResult ==4 ? wrongans : normal
                                    radius: 30
                                    border.color: boderColor
                                    border.width: 2
                                    Label {
                                        anchors.centerIn: parent
                                        text: "<b> <font color=\"#ffea00\">C:</font> <font color=\"#ffea00\"> </font><b>" + client.packc
                                        color: textColor
                                    }
                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            client.sendAnswer(2)
                                            client.cResult = 0
                                        }
                                    }
                                }
                                Rectangle {
                                    id: packD
                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    color: client.dResult===0 ? choosen : client.dResult===1 ? correct : client.dResult===2 ? correctans : client.dResult ==4 ? wrongans : normal
                                    radius: 30
                                    border.color: boderColor
                                    border.width: 2
                                    Label {
                                        anchors.centerIn: parent
                                        text: "<b> <font color=\"#ffea00\">D:</font> <font color=\"#ffea00\"> </font><b>" + client.packd
                                        color: textColor
                                        horizontalAlignment: Text.AlignLeft
                                    }
                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            client.sendAnswer(3)
                                            client.dResult = 0
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
                            Rectangle { height: parent.height; width: parent.height; color: avatar; radius: 10 }
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

