import QtQuick 2.0
import MusicLyricsListModel 1.0

Rectangle {
    width: parent.width; height: parent.height
//    color: "lightblue"
    color: "#00000000"

    ListView {
        id: listViewId
        width: parent.width; height: parent.height
        clip: true
        model: musicLyricsListModel
        currentIndex: musicLyricsListModel.currentIndex

        delegate:
        Rectangle {
            width: listViewId.width; height: listViewId.height/10

            Text {
                anchors.centerIn: parent
                font.pixelSize: parent.height/3
                text: modelData.content
                color: "black"
            }

//            Rectangle {
//                anchors.bottom: parent.bottom
//                width: parent.width; height: 1
//                color: "#d5d5d5"
//            }
        }
    }

    MusicLyricsListModel {
        id: musicLyricsListModel
    }
}
