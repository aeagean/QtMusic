/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
import QtQuick 2.0

Rectangle {
    property string musicName: ""
    width: parent.width; height: parent.height
//    color: "lightblue"
    color: "#00000000"

    Text {
        text: musicName
        anchors.centerIn: parent
        font.pixelSize: parent.height/2
    }

    Rectangle {
        anchors.bottom: parent.bottom
        width: parent.width; height: parent.height/30;
        color: "#d5d5d5"
    }
}
