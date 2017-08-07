import QtQuick 2.0

Item {
    width: parent.width; height: parent.height

    Row {
        anchors.fill: parent

        Rectangle {
            width: parent.width/6; height: parent.height
//            color: "lightblue"
        }

        Rectangle {
            width: 4.3*parent.width/6; height: parent.height
//            color: "red"

            Text {
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width
                elide: Text.ElideMiddle
                color: "black"
                font.pixelSize: parent.height/3.5
                text: modelData.pathName
            }
        }
    }

    Rectangle {
        anchors.bottom: parent.bottom;
        anchors.right: parent.right
        width: parent.width - parent.width/6; height: 1;
        color: "#f2f2f2"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            fileBrowserListModel.pathName = fileBrowserListModel.pathName + "/" + modelData.pathName
        }
    }
}
