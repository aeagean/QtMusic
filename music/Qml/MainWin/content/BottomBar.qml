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
                btnText: "Add"
                onIsClicked: fileBrowser.visible = true
            }
            BaseButton {
                width: parent.width/5; height: parent.height
            }
            BaseButton {
                width: parent.width/5; height: parent.height
                color: "green"
                btnText: musicPlayControl.playbackModeStr
                onIsClicked: musicPlayControl.changedPlaybackMode()
            }
            BaseButton {
                width: parent.width/5; height: parent.height
            }
            BaseButton {
                width: parent.width/5; height: parent.height
                color: "green"
                btnText: "List"
                onIsClicked: musicPlayListWin.visible = true
            }
        }
    }

}
