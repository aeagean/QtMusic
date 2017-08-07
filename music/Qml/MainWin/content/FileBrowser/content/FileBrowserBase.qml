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
//            color: "lightblue"
        }
    }
}
