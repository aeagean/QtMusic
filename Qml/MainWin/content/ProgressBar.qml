/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
import QtQuick 2.0
import "../../Common/SliderBar"

Item {
    property variant musicPlayControlModel
    width: parent.width; height: parent.height

    Row {
        anchors.fill: parent

        Rectangle {
            width: parent.width/5; height: parent.height
            color: "#00000000"
            Text {
                anchors.centerIn: parent
                font.pixelSize: parent.height/1.8
                color: "#474747"
                text: musicPlayControl.leftTimeStr
            }
        }

        SliderBar {
            id: sliderBarId
            width: 3*parent.width/5; height: parent.height
            color: "#00000000"
            value: musicPlayControl.progressBarValue
            onValueSig: musicPlayControl.progressBarValue = val
        }

        Rectangle {
            width: parent.width/5; height: parent.height
            color: "#00000000"
            Text {
                anchors.centerIn: parent
                font.pixelSize: parent.height/1.8
                color: "#474747"
                text: musicPlayControl.rightTimeStr
            }
        }
    }
}
