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
        spacing: parent.width/30

        Rectangle {
            width: parent.width/7; height: parent.height

            Image {
                width: 0.4*(parent.width > parent.height ? parent.height:parent.width);
                height: width
                anchors.centerIn: parent
                source: "qrc:/Resource/MusicPicture/LeftArrow.png"
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
                text: "Select folder"
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
