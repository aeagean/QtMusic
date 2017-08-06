import QtQuick 2.0
import "../Common"

Rectangle {
    signal clickedChanged()
    property int size: parent.height/*parent.width > parent.height ? (parent.width * 3* 0.1) : parent.height*3*0.1*/
    property bool isStartStatus: false
    id: backGroundId
    width: size; height: size
    radius: size/2
    color: "#00000000"
    border.width: size/25
    border.color: "#e9e9e9"

    Row {
        id: doubleRectangleId
        visible: isStartStatus
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

    Triangle {
        id: triangleId
        visible: !isStartStatus
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -width/10
        width: size/2.3; height: size/2
        rotation: 180
    }

    MouseArea {
        anchors.fill: parent
        onClicked: clickedChanged()
        onPressed: backGroundId.color = "#CDC9C9"
        onReleased: backGroundId.color = "#00000000"
    }
}
