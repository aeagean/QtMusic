import QtQuick 2.0

Rectangle {
    signal clickedChanged()
    property int size: 75
    id: backGroundId
    width: size; height: size
    radius: size/2
    color: "#00000000"
    border.width: size/25
    border.color: "#e9e9e9"

    Row {
        anchors.centerIn: parent
        spacing: size/8

        Rectangle {
            width: size/10; height: size/2.3
            color: "#474747"
        }

        Rectangle {
            width: size/10; height: size/2.3
            color: "#474747"
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: clickedChanged()
        onPressed: backGroundId.color = "#CDC9C9"
        onReleased: backGroundId.color = "#00000000"
    }
}
