import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Rectangle {
    width: 200
    height: 100
    color: "red"

    Text {
        anchors.centerIn: parent
        text: "Hello, World!"
    }

    //    focus: true
    //    Keys.onPressed: {
    //        if (event.key == Qt.Key_Return) {
    //            color = "blue"
    //            event.accepted = true
    //        }
    //    }
}
