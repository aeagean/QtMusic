import QtQuick 2.0

Rectangle {
    signal backed()
    id: rectId
    width: parent.width; height: parent.height
//    color: "lightblue"

    Row {
        anchors.fill: parent

        Rectangle {
            width: parent.width/7; height: parent.height

            Text {
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: -parent.height/20
                anchors.horizontalCenter: parent.horizontalCenter
                color: "#474747"
                text: "<"
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
}
