import QtQuick 2.5
import QtQuick.Window 2.2
import "qml/uiItem"

Window {
    visible: true
    width: 1920*0.3
    height: 1080*0.3
    title: qsTr("Hello World")

    LeftDoubleTriangle {
        anchors.centerIn: parent
        size: 20
    }

//    Rectangle {
//        width: 200; height: 200
//        color: "lightblue"

//        Triangle {
//            anchors.centerIn: parent
//            width: 32; height: 40
//        }
//    }
}
