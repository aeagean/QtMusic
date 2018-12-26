/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
import QtQuick 2.0
import "../../Common"

Item {
    property variant musicPlayControlModel
    width: parent.width; height: parent.height/10

    Row {
        width: parent.width; height: parent.height

        Item {
            width: parent.width/3; height: parent.height
            PreOrNextButton {
                direction: "left"
                anchors.centerIn: parent
                onClickedChanged: musicPlayControlModel.prevMusic();
            }
        }

        Item {
            width: parent.width/3; height: parent.height
            StartOrStopButton {
                anchors.centerIn: parent
                isStartStatus: musicPlayControlModel.isStart
                onClickedChanged: musicPlayControlModel.isStart = !musicPlayControlModel.isStart
            }
        }
        Item {
            width: parent.width/3; height: parent.height
            PreOrNextButton {
                direction: "right"
                anchors.centerIn: parent
                onClickedChanged: musicPlayControlModel.nextMusic()
            }
        }
    }
}
