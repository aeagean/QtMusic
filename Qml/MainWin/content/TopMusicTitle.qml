import QtQuick 2.0

Rectangle {
    property string musicName: ""
    width: parent.width; height: parent.height
//    color: "lightblue"
    color: "#00000000"

    Text {
        text: musicName
        anchors.centerIn: parent
        font.pixelSize: parent.height/1.8
    }

    Rectangle {
        anchors.bottom: parent.bottom
        width: parent.width; height: parent.height/30;
        color: "#d5d5d5"
    }
}
