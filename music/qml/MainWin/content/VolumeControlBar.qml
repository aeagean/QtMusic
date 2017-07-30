import QtQuick 2.0

Item {
    width: parent.width; height: parent.height

    Row {
        anchors.fill: parent

        Rectangle {
            width: parent.width/5; height: parent.height
            color: "lightblue"
            Text {
                anchors.centerIn: parent
                font.pixelSize: parent.height/1.8
                color: "#474747"
                text: "00:00"
            }
        }

        Rectangle {
            width: 3*parent.width/5; height: parent.height
            color: "blue"
        }

        Rectangle {
            width: parent.width/5; height: parent.height
            color: "lightblue"
            Text {
                anchors.centerIn: parent
                font.pixelSize: parent.height/1.8
                color: "#474747"
                text: "03:00"
            }
        }
    }
}
