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

import QtQml 2.2

ApplicationWindow {
    id: root
    visible: true
    width: 1200
    height: 620

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



    MainWindow {
        id: client
    }

    Item {
        id: list
        function myQmlFunction(msg) {
              console.log("Got message:", msg)
              return "some return value"
        }
    }


    ColumnLayout{
        spacing: 2
        Layout.alignment: Qt.AlignHCenter
        Layout.fillWidth: true
        Layout.fillHeight: true
        id : welcomePage

        Text {
            id : lable
            text: "Please enter your name:"
            font.family: "Helvetica"
            font.pointSize: 16
            color: "black"
            Layout.alignment: Qt.AlignHCenter
        }

        TextEdit {
            id: edit
            anchors.topMargin: 10
            anchors.leftMargin: 10
            focus: true
            wrapMode: TextEdit.Wrap
            Layout.alignment: Qt.AlignHCenter
        }

        Button {
          anchors.topMargin: 40
          anchors.leftMargin: 20
          text: "Continue"
          onClicked: {
              client.createMe(edit.text)
              welcomePage.visible = false
              onGameLayout.visible = true
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
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredHeight: 3
                    source: "qrc:/shared/2.jpg"

                    Item {
                        id: packTimer
                        Canvas {
                            id: canvas
                            width: 240
                            height: 240
                            antialiasing: true

                            property color primaryColor: "gray"
                            property color secondaryColor: "#ff36ab"

                            property real centerWidth: width / 2
                            property real centerHeight: height / 2
                            property real radius: Math.min(canvas.width, canvas.height) / 2

                            property real minimumValue: 0
                            property real maximumValue: 100
                            property real currentValue: 33

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
                                    ctx.lineWidth = 5;
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
                                ctx.lineWidth = 5;
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
                                ctx.lineWidth = 5;
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

                            Text {
                                anchors.centerIn: parent

                                text: canvas.text
                                color: canvas.primaryColor
                            }

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
                             interval: 1000
                             repeat: true
                             running: true
                             onTriggered: canvas.currentValue < canvas.maximumValue ? canvas.currentValue += 1.0 : canvas.currentValue = canvas.minimumValue
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
                                anchors.centerIn: parent
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
            color: "#010103"
                ListView {
                    property var columnWidths: ({"avatar": 50, "name": 100, "code": 50}) // fixed sizes or minimum sizes
                    property var calculatedColumns: ["code", "language"]   // list auto sized columns in here

                    orientation: Qt.Vertical
                    anchors.fill: parent
                    model: PlayerModel {
                        list: playerList
                    }
                    anchors.margins: 10
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
                                    Layout.preferredWidth: 2
                                    text: '<b> ' + name + '</b> '
                                    color: "pink"
                                }

                                Label {
                                    Layout.fillHeight: true
                                    Layout.fillWidth: true
                                    Layout.preferredHeight: implicitHeight
                                    text: score
                                    color: "pink"
                                }
                            }
                        }
                    }
                }
        }

        }
}

