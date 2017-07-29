import QtQuick 2.0

Rectangle {
    property int size: 50
    width: size; height: size
    radius: size/2
    color: "#00000000"
    border.width: size/25
    border.color: "#e9e9e9"

    DoubleTriangle {
        anchors.centerIn: parent
        size: parent.size/3
    }
}
