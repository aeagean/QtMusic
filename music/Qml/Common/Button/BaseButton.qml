import QtQuick 2.0

Rectangle {
    signal isClicked()
    width: parent.width; height: parent.height
    color: "#00000000"

    MouseArea {
        anchors.fill: parent
        onClicked: isClicked()
    }
}
