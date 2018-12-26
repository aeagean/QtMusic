/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
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
                onIsClicked: musicPlayListWin.visible = false

                Image {
                    width: 0.4*(parent.width > parent.height ? parent.height:parent.width);
                    height: width
                    anchors.centerIn: parent
                    source: "qrc:/Resource/MusicPicture/LeftArrow.png"
                }
            }

        }

        MusicListContent {
            id: listViewId
            width: parent.width; height: (20-1.5)*parent.height/20
        }
    }

    Text {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        text: "源码地址: https://github.com/aeagean/QtMusic"
        visible: !listViewId.count
    }
}
