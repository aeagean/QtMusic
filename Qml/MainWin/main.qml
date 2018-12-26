/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtMultimedia 5.0
//import MusicPlayControl 1.0
import MusicPlayListModel 1.0
import "../Common"
import "content"
import "../Common/SliderBar"
import "../FileBrowserWin"
import "../MusicPlayListWin"

Window {
    visible: true
    width: 1080*0.3
    height: 1920*0.3
    title: qsTr("音乐播放器")

    Column {
        anchors.fill: parent

        TopMusicTitle {
            width: parent.width; height: 1.5*parent.height/30
            musicName: musicPlayControl.musicName
        }

        LyricsDisplayArea {
            width: parent.width; height: 21*parent.height/30
        }

        Item { width: parent.width; height: 0.5*parent.height/30 }

        ProgressBar {
            musicPlayControlModel: musicPlayControl
            width: parent.width; height: 1*parent.height/30
        }

        Item { width: parent.width; height: 0.5*parent.height/30 }

        MusicPlayControlBar {
            width: parent.width; height: 3*parent.height/30
            musicPlayControlModel: musicPlayControl
        }

        Item { width: parent.width; height: 0.5*parent.height/30 }

        BottomBar {
            width: parent.width; height: 2*parent.height/30
        }
    }


    // -------------------------------------------------------------------------------

    /*FileBrowser win*/
    FileBrowser {
        id: fileBrowser
        anchors.fill: parent
        visible: false
    }

    MusicPlayListWin {
        id: musicPlayListWin
        anchors.fill: parent
        visible: false
    }

    // ---------------------------------------------------------------

    MusicPlayListModel {
        id: musicPlayListModel
    }
}
