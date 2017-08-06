import QtQuick 2.0
import MusicPlayControl 1.0
import "../../Common"

Row {
    width: parent.width; height: parent.height/10

    Item {
        width: parent.width/3; height: parent.height
        PreOrNextButton {
            direction: "left"
            anchors.centerIn: parent
        }
    }

    Item {
        width: parent.width/3; height: parent.height
        StartOrStopButton {
            anchors.centerIn: parent
            isStartStatus: musicPlayControl.isStart
            onClickedChanged: musicPlayControl.isStart = !musicPlayControl.isStart
        }
    }
    Item {
        width: parent.width/3; height: parent.height
        PreOrNextButton {
            direction: "right"
            anchors.centerIn: parent
        }
    }

    MusicPlayControl {
        id: musicPlayControl
        isStart: false
    }
}
