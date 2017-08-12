import QtQuick 2.0
import "../../Common/Button"

Rectangle {
    width: parent.width; height: parent.height
    color: "lightblue"

    Rectangle {
        anchors.centerIn: parent
        width: parent.width*0.7; height: parent.height
        color: "lightblue"

        Row {
            width: parent.width; height: parent.height

            BaseButton {
                width: parent.width/5; height: parent.height
                color: "red"
                onIsClicked: fileBrowser.visible = true
            }
            BaseButton {
                width: parent.width/5; height: parent.height
            }
            BaseButton {
                width: parent.width/5; height: parent.height
                color: "green"
            }
            BaseButton {
                width: parent.width/5; height: parent.height
            }
            BaseButton {
                width: parent.width/5; height: parent.height
                color: "green"
                onIsClicked: musicPlayListWin.visible = true
            }
        }
    }

}
