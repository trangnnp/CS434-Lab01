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
import "../shared" as Examples
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQml.Models 2.15
import QtQuick.Controls.Styles 1.4

import MainWindow 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 1200
    height: 620

    property var choosen: "#f4a261"
    property var correctans: "#e76f51"
    property var normal: "#eec1a2"
    property var wrongans: "#354f52"
    property var correct: "#81b29a"



    MainWindow {
        id: client
    }

//    #443224 eec1a2


    ColumnLayout{
        spacing: 2
        Layout.alignment: Qt.AlignHCenter
        Layout.fillWidth: true
        Layout.fillHeight: true
        id : welcomePage
//        color: "#5d5b59"


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
            width: flick.width
            focus: true
            wrapMode: TextEdit.Wrap
            Layout.alignment: Qt.AlignHCenter
        }

        Button {
          anchors.top: parent.top
          anchors.left: parent.left
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
                Image {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredHeight: 2
                    source: "qrc:/shared/coffee2.jpg"

                }
                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredHeight: 1
                    color: "#1e1b18"

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 40

                        Rectangle {
                            id: packQ
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            Layout.preferredHeight: 3
                            color: "#FFBD99"
                            radius: 20
                            Label {
                                anchors.centerIn: parent
                                text: client.packq
                                color: "#443224"
                            }
                        }

                        Rectangle {
                            id: packAB
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            anchors.margins: 20
                            Layout.preferredHeight: 2
                            color: "#1e1b18"

                            RowLayout {
                                anchors.fill: parent
                                Rectangle {
                                    id: packA

                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    color: client.aResult===0 ? choosen : client.aResult===1 ? correct : client.aResult===2 ? correctans : client.aResult ==4 ? wrongans : normal
                                    radius: 30
                                    Label {
                                        anchors.centerIn: parent
                                        text: '<b>A:</b> ' + client.packa
                                        color: "#443224"
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
                                    Label {
                                        anchors.centerIn: parent
                                        text: '<b>B:</b> ' + client.packb
                                        color: "#443224"
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
                            color: "#1e1b18"

                            RowLayout {
                                anchors.fill: parent
                                Rectangle {
                                    id: packC
                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    color: client.cResult===0 ? choosen : client.cResult===1 ? correct : client.cResult===2 ? correctans : client.cResult ==4 ? wrongans : normal
                                    radius: 30
                                    Label {
                                        anchors.centerIn: parent
                                        text: '<b>C:</b> ' + client.packc
                                        color: "#443224"
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
                                    Label {
                                        anchors.centerIn: parent
                                        text: '<b>D:</b> ' + client.packd
                                        color: "#443224"
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
            color: "#1e1b18"
            ListModel {
                    id: listModel
                    ListElement { name: 'Meo1'; code: "12.000.000"; language: "english" }
                    ListElement { name: 'Meo2'; code: "10.000.000"; language: "french" }
                    ListElement { name: 'Meo3'; code: "900.000"; language: "long-language" }
                }

                ListView {
                    property var columnWidths: ({"avatar": 50, "name": 100, "code": 50}) // fixed sizes or minimum sizes
                    property var calculatedColumns: ["code", "language"]   // list auto sized columns in here

                    orientation: Qt.Vertical
                    anchors.fill: parent
                    model: listModel
                    anchors.margins: 10
                    spacing: 10

//                    TextMetrics {
//                        id: textMetrics
//                    }

//                    onModelChanged: {
//                        for (var i = 0; i < calculatedColumns.length; i++) {
//                            var role = calculatedColumns[i]
//                            if (!columnWidths[role]) columnWidths[role] = 0
//                            var modelWidth = columnWidths[role]
//                            for(var j = 0; j < model.count; j++){
//                                textMetrics.text = model.get(j)[role]
//                                modelWidth = Math.max(textMetrics.width, modelWidth)
//                            }
//                            columnWidths[role] = modelWidth
//                        }
//                    }

                    delegate: Component {
                        Row {
                            spacing: 10
                            Rectangle { height: parent.height; width: parent.height; color: "pink" }
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
                                    Layout.preferredWidth: columnWidths.code
                                    text: code
                                    color: "pink"
                                }

                            }
                        }
                    }

//                    delegate: RowLayout {

//                        property var columnWidths: ListView.view.columnWidths

//                        Rectangle {
//                            id: avatar
//                            Layout.fillHeight: true
//                            Layout.fillWidth: true
//                            Layout.preferredHeight: implicitHeight
//                            Layout.preferredWidth: 1
//                            color: "pink"
//                        }

//                        Rectangle {
//                            Layout.fillHeight: true
//                            Layout.fillWidth: true
//                            Layout.preferredHeight: implicitHeight
//                            Layout.preferredWidth: 2
//                            color: "pink"
//                            Label {
//                                Layout.fillHeight: true
//                                Layout.fillWidth: true
//                                Layout.preferredHeight: implicitHeight
//                                Layout.preferredWidth: 2
//                                text: name
//                                color: "pink"
//                            }

//                        }


//                        Label {
//                            Layout.fillHeight: true
//                            Layout.fillWidth: true
//                            Layout.preferredHeight: implicitHeight
//                            Layout.preferredWidth: columnWidths.code
//                            text: code
//                            color: "pink"
//                        }

////                        Label {
////                            Layout.fillHeight: true
////                            Layout.fillWidth: true
////                            Layout.preferredHeight: implicitHeight
////                            Layout.preferredWidth: columnWidths.language
////                            text: language
////                            color: "pink"
////                        }
//                    }
                }

        }
    }
}

