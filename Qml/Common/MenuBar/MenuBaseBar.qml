import QtQuick 2.0

Rectangle {
    property string titleText
    property string titleTextColor: "#5c626d"
    property color colorBar: "white"
    width: parent.width
    height: parent.height
    color: colorBar

    Text {
        text: titleText
        anchors.centerIn: parent
        font.pixelSize: 35
        color: titleTextColor
    }

    Rectangle{
        anchors.bottom: parent.bottom
        width: parent.width; height: parent.height/30;
        color: "#e1e5ee"
    }
}
