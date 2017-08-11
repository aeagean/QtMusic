import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtMultimedia 5.0
import MusicPlayControl 1.0
import "../Common"
import "content"
import "../Common/SliderBar"
import "../FileBrowserWin"

Window {
    visible: true
    width: 1080*0.3
    height: 1920*0.3
    title: qsTr("Music")

    Column {
        anchors.fill: parent

        Item { width: parent.width; height: 24*parent.height/30}

        ProgressBar {
            musicPlayControlModel: musicPlayControl
            width: parent.width; height: parent.height/30
        }

        MusicPlayControlBar {
            width: parent.width; height: 3*parent.height/30
            musicPlayControlModel: musicPlayControl
        }

        BottomBar {
            width: parent.width; height: 2*parent.height/30
        }
    }

    FileBrowser {
        anchors.fill: parent
    }

    // data control
    MusicPlayControl {
        id: musicPlayControl
        isStart: false
    }
}
