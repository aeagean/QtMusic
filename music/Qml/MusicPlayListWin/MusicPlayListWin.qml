import QtQuick 2.0
import "./content"
import "../Common/MenuBar"
import "../Common/Button"

Rectangle {
    id: musicPlayListWin
    width: parent.width; height: parent.height

    Column {
        anchors.fill: parent

        MenuBaseBar {
            width: parent.width; height: 1.5*parent.height/20

            BaseButton {
                width: parent.width/7; height: parent.height
                color: "lightblue"
                onIsClicked: musicPlayListWin.visible = false
            }

        }

        MusicListContent {
            width: parent.width; height: (20-1.5)*parent.height/20
        }
    }
}
