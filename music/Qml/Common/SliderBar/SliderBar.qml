import QtQuick 2.0

Rectangle {
    signal valueSig(real val)
    signal pressedSig();
    property real value: 0.5 //0.1-1.0

//    width: parent.width; height: parent.height
    color: "#00000000"

    onWidthChanged: sliderId.x = value*(width)-width/40
    onValueChanged: sliderId.x = value*(rectBackgroundId.width)-rectBackgroundId.width/40

    Rectangle {
        id: rectBackgroundId
        width: parent.width; height: parent.height/5
        anchors.centerIn: parent
        color: "#e9e9e9"
    }

    Rectangle {
        id: sliderId
        width: parent.width/20; height: parent.height
        color: "#00000000"
        x: value*(rectBackgroundId.width)-rectBackgroundId.width/40

        Rectangle {
            anchors.centerIn: parent
            width: parent.width/2; height: parent.height/1.1
            color: "#474747"
        }

        MouseArea {
            id: mouseAreaId
            anchors.fill: parent
            drag.target : sliderId
            drag.axis: Drag.XAxis
            drag.minimumX : -parent.width/2
            drag.maximumX : rectBackgroundId.width - parent.width/2
            onPressed: pressedSig()
            onReleased: valueSig((sliderId.x+sliderId.width/2)/rectBackgroundId.width)
        }
    }
}
