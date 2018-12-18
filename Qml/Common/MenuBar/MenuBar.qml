import QtQuick 2.0

MenuBaseBar{
    property string title: "Titletext"
    property string leftBtnText
    property string rightBtnText
    signal leftBtnSelected()
    signal rightBtnSelected()

    titleText: title
}
