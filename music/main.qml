import QtQuick 2.5
import QtQuick.Window 2.2
import "qml/uiItem"

Window {
    visible: true
    width: 1080*0.3
    height: 1920*0.3
    title: qsTr("Music")

    PreOrNextButton {
        anchors.horizontalCenter: parent.horizontalCenter
        size: parent.width > parent.height ? (parent.width*0.08) : parent.height*0.08
    }

    PreOrNextButton {
        size: parent.width > parent.height ?
                  (parent.width * 0.08) : parent.height*0.08
        rotation: 180
    }

    StartOrStopButton {
        anchors.verticalCenter: parent.verticalCenter
        size: parent.width > parent.height ?
                  (parent.width * 0.1) : parent.height*0.1
    }
}
