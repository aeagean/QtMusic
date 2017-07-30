import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import "../Common"
import "content"
import "../Common/SliderBar"

Window {
    visible: true
    width: 1080*0.3
    height: 1920*0.3
    title: qsTr("Music")

    Column {
        anchors.fill: parent

        VolumeControlBar {
            width: parent.width; height: parent.height/30

        }

        MusicPlayControlBar {
            width: parent.width; height: parent.height/10
        }

//        Slider {

//        }

        SliderBar {
           width: 3*parent.width/5; height: parent.height/30
//            rotation: 90
           onValueSig: value = val
        }
    }
}
