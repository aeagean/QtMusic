import QtQuick 2.0

Rectangle {
    signal clickedChanged()
    property int size: 50
    id: backGroundId
    width: size; height: size
    radius: size/2
    color: "#00000000"
    border.width: size/25
    border.color: "#e9e9e9"

    DoubleTriangle {
        anchors.centerIn: parent
        size: parent.size/3
    }

    MouseArea {
        anchors.fill: parent
        onClicked: clickedChanged()
        onPressed: backGroundId.color = "#CDC9C9"
        onReleased: backGroundId.color = "#00000000"
    }
}
