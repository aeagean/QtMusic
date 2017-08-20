import QtQuick 2.0
import "../../Common/Button"

Rectangle {
    width: parent.width; height: parent.height
//    color: "lightblue"

    Rectangle {
        anchors.centerIn: parent
        width: parent.width*0.7; height: parent.height
//        color: "lightblue"

        Row {
            width: parent.width; height: parent.height

            BaseButton {
                width: parent.width/5; height: parent.height
                Image {
                    anchors.centerIn: parent
                    scale: 0.5
                    source: "qrc:/Resource/MusicPicture/PlayList.png"
                }
                onIsClicked: musicPlayListWin.visible = true
            }


            BaseButton {
                width: parent.width/5; height: parent.height
            }
            BaseButton {
                width: parent.width/5; height: parent.height
                Image {
                    anchors.centerIn: parent
                    scale: 0.5
                    source: "qrc:/Resource/MusicPicture/"+musicPlayControl.playbackModeStr+".png"
                }
                onIsClicked: musicPlayControl.changedPlaybackMode()
            }
            BaseButton {
                width: parent.width/5; height: parent.height
            }

            BaseButton {
                width: parent.width/5; height: parent.height
                Image {
                    anchors.centerIn: parent
                    scale: 0.48
                    source: "qrc:/Resource/MusicPicture/Add.png"
                }
                onIsClicked: fileBrowser.visible = true
            }
        }
    }

}
