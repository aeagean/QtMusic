/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
import QtQuick 2.0

Rectangle {
    id: rectId
    width: parent.width; height: parent.height
    color: "#f2f2f2"

    ListView {
        id: listViewId
        width: parent.width; height: parent.height
        clip: true
        orientation: ListView.Horizontal
        model: fileBrowserListModel.displayPathNameList
        delegate: Item {
            width: textId.width /*+ 10*/; height: rectId.height

            Text {
                id: textId
                anchors.centerIn: parent
                color: "#474747"
                text:  modelData === "" ? "    "+"disk"+"    >" : "    "+modelData+"    >"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: fileBrowserListModel.cdPath(listViewId.count - index)
            }
        }
    }
}
