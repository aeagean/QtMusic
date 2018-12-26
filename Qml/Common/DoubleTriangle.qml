/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
import QtQuick 2.0

Item {
    property int size: 40
    width: item.scaleValue*size + item.location; height: size //private

    Triangle {
        z: 1.5
        width: size*item.scaleValue; height: size
        rotation: 180
    }
    Triangle {
        x: item.location
        width: size*item.scaleValue; height: size
        rotation: 180
    }

    Item {
        id: item
        property var scaleValue: 0.8
        property var location: size/1.8
    }
}
