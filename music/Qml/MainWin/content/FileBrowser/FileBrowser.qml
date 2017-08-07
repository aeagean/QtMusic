import QtQuick 2.0
import FileBrowserListModel 1.0
import "content"

Rectangle {
    anchors.fill: parent

    MouseArea { anchors.fill: parent }

    Column {
        anchors.fill: parent

        FileBrowserTitleBar {
            width: parent.width; height: parent.height/17
            onBacked: fileBrowserListModel.pathName = "/"
        }

        FileBrowserSimpleFileList { width: parent.width; height: parent.height/19}

        FileBrowserBase { width: parent.width; height: parent.height - parent.height/17 - parent.height/19}
    }

    FileBrowserListModel {
        id: fileBrowserListModel
        pathName: "/"
    }
}
