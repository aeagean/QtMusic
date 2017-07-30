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

        ProgressBar {
            width: parent.width; height: parent.height/30
        }

        MusicPlayControlBar {
            width: parent.width; height: parent.height/10
        }
    }
}
