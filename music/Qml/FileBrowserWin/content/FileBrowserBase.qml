import QtQuick 2.0

Rectangle {
    width: parent.width; height: parent.height
//    color: "lightblue"

    Column {
        anchors.fill: parent

        ListView {
            id: listViewId
            width: parent.width; height: 9*parent.height/10
            clip: true
            model: fileBrowserListModel

            delegate: FileBrowserBaseDelegate { width: listViewId.width; height: listViewId.height/7 }
        }

        Rectangle {
            width: parent.width; height: parent.height/10

            Rectangle { width: parent.width; height: parent.height; color: "#f2f2f2" }

            Text {
                anchors.centerIn: parent
                text: "增加"
                font.pixelSize: parent.height/2.5
            }

            MouseArea {
                anchors.fill: parent
                onClicked: fileBrowserListModel.save()
            }
        }
    }
}
