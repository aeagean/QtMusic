/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
import QtQuick 2.0

Rectangle {
    signal clickedChanged()
    property int size: 0.8*parent.height//parent.width > parent.height ? (parent.width*3*0.08) : parent.height*3*0.08
    property string direction: "left" // [0]>"left"; [1]>"right"
    id: backGroundId
    width: size; height: size
    radius: size/2
    color: "#00000000"
    border.width: size/25
    border.color: "#e9e9e9"
    rotation: direction === "left" ? 0 : 180

    DoubleTriangle {
        anchors.centerIn: parent
        size: parent.size/3
    }

    MouseArea {
        anchors.fill: parent
        onClicked: clickedChanged()
        onPressed: backGroundId.color = "#CDC9C9"
        onReleased: backGroundId.color = "#00000000"
    }
}
