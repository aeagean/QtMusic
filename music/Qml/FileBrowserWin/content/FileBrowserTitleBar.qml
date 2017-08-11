import QtQuick 2.0

Rectangle {
    signal backed()
    id: rectId
    width: parent.width; height: parent.height
    //    color: "lightblue"

    Row {
        id: statusOneId
        visible: true
        anchors.fill: parent

        Rectangle {
            width: parent.width/7; height: parent.height

            Text {
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: -parent.height/20
                anchors.horizontalCenter: parent.horizontalCenter
                color: "#474747"
                text: "＜"
                font.pixelSize: parent.height
            }

            MouseArea {
                anchors.fill: parent
                onClicked: backed()
            }
        }

        Rectangle {
            width: parent.width/5; height: parent.height

            Text {
                anchors.centerIn: parent
                color: "black"
                text: "选择文件夹"
                font.pixelSize: parent.height/2.5
            }
        }
    }

    Row {
        id: statusTwoId
        visible: false
        anchors.fill: parent

        Rectangle {
            width: parent.width/7; height: parent.height
            color: "lightblue"

            Text {
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: parent.width/3
                color: "black"
                text: "取消"
                font.pixelSize: parent.height/2.5
            }

            MouseArea {
                anchors.fill: parent
                onClicked: statusTwoId.visible = false
            }
        }

        Rectangle {
            width: 5*parent.width/7; height: parent.height
        }

        Rectangle {
            width: parent.width/7; height: parent.height

            Text {
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: parent.width/3
                color: "black"
                text: fileBrowserListModel.isAllSelected ? "全选" : "全不选"
                font.pixelSize: parent.height/2.5
            }

            MouseArea {
                anchors.fill: parent
                onClicked: fileBrowserListModel.isAllSelected = !fileBrowserListModel.isAllSelected
            }
        }
    }
}
