/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
import QtQuick 2.0

MenuBaseBar{
    property string title: "Titletext"
    property string leftBtnText
    property string rightBtnText
    signal leftBtnSelected()
    signal rightBtnSelected()

    titleText: title
}
