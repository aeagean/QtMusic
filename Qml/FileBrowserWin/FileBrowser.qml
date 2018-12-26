/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
import QtQuick 2.0
import FileBrowserListModel 1.0
import "content"

Rectangle {
    id: fileBrowser
//    visible: false
    anchors.fill: parent

    MouseArea { anchors.fill: parent }

    Column {
        anchors.fill: parent

        FileBrowserTitleBar {
            width: parent.width; height: 1.5*parent.height/20
            onBacked: fileBrowser.visible = false
        }

        FileBrowserSimpleFileList { width: parent.width; height: 1*parent.height/20 }

        FileBrowserBase { width: parent.width; height: 16*parent.height/20 }

        FileBrowserAddBtnBar {
            width: parent.width; height: (20-16-1-1.5)*parent.height/20
            onBtnAdded: {
                fileBrowser.visible = false
                fileBrowserListModel.save()
            }
        }
    }

    //-------------------------------------------------------
    // data
    FileBrowserListModel {
        id: fileBrowserListModel
    }
}
