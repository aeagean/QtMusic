import QtQuick 2.0
import "../../Common/Button"

Rectangle {
    width: parent.width; height: parent.height

    Rectangle { width: parent.width; height: parent.height/30; color: "#f2f2f2" }

    Text {
        id: textId
        anchors.centerIn: parent
        text: "增加"
        font.pixelSize: parent.height/2.5
    }

    MouseArea {
        anchors.fill: parent
        onClicked: fileBrowserListModel.save()
        onPressed: {
            textId.color = "white"
            parent.color = "#CDC9C9"
        }
        onReleased: {
            textId.color = "black"
            parent.color = "white"
        }
    }
}

