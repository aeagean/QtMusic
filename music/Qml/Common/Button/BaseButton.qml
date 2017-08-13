import QtQuick 2.0

Rectangle {
    signal isClicked()
    property string btnText: ""
    property variant textObj: textId
    width: parent.width; height: parent.height
    color: "#00000000"

    Text {
        id: textId
        anchors.centerIn: parent
        text: btnText
        font.pixelSize: parent.height/2.5
    }

    MouseArea {
        anchors.fill: parent
        onClicked: isClicked()
    }
}
