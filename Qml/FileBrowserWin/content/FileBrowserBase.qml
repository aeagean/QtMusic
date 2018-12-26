/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
import QtQuick 2.0

Rectangle {
    width: parent.width; height: parent.height
//    color: "lightblue"

    ListView {
        id: listViewId
        width: parent.width; height: parent.height
        clip: true
        model: fileBrowserListModel

        delegate: FileBrowserBaseDelegate { width: listViewId.width; height: listViewId.height/7 }
    }
}
