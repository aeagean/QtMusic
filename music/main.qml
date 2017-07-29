import QtQuick 2.5
import QtQuick.Window 2.2
import "qml/uiItem"

Window {
    visible: true
    width: 1080*0.3
    height: 1920*0.3
    title: qsTr("Hello World")

    PreOrNextButton {
        anchors.horizontalCenter: parent.horizontalCenter
        size: parent.width > parent.height ? (parent.width*parent.width/50) : parent.height/50
    }

    PreOrNextButton {
        size: parent.width > parent.height ?
                  (parent.width * parent.width/50) : parent.height/50
        rotation: 180
    }
}
