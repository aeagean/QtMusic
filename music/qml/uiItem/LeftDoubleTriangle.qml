import QtQuick 2.0

Item {
    property int size: 40
    width: size; height: size
    Triangle {
        z: 1.5
        width: parent.width*0.8; height: parent.width
        rotation: 180
    }
    Triangle {
        x: parent.width/2.1
        width: parent.width*0.8; height: parent.width
        rotation: 180
    }
}
