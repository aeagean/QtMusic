/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
import QtQuick 2.0
import MusicLyricsListModel 1.0
import QtGraphicalEffects 1.0

Rectangle {
    width: parent.width; height: parent.height
//    color: "lightblue"
    color: "#00000000"

    ListView {
        id: listViewId
        width: parent.width; height: parent.height
        clip: true
        model: musicLyricsListModel
        currentIndex: musicLyricsListModel.currentIndex
        highlightRangeMode: ListView.StrictlyEnforceRange

        delegate: lrcDelegate
    }

    MusicLyricsListModel {
        id: musicLyricsListModel
    }

    Component {
        id: lrcDelegate

        Rectangle {
           width: listViewId.width; height: listViewId.height/10
          // color: ListView.isCurrentItem ? "black" : "red"
           id: wrapper

           Text {
               id: mt
               visible: false
               anchors.centerIn: parent
               font.pixelSize: parent.height/3
               //property string msg : modelData.content + ":" + listViewId.currentIndex;
               text: modelData.content
               color: wrapper.ListView.isCurrentItem ? "red" : "black"
           }

           PropertyAnimation {
               target: mr1
               property: "width"
               from: 0
               to: m2.width
               duration: modelData.duration
               loops: 1
               running: wrapper.ListView.isCurrentItem
           }

           Rectangle {
               id: m2
               anchors.fill: mt
               color: "#00000000"
               Rectangle {
                   id: mr1
                   height: parent.height
                   color: "blue"
                   //width是从0到m2.width
               }

               Rectangle {
                   x: mr1.width  //从0到m2.width
                   height: parent.height
                   width: m2.width - mr1.width
                   color: "red"
               }
           }

           ShaderEffectSource {
                id: mask
                visible: false
                anchors.fill: mt
                hideSource : true
                sourceItem: m2
            }

           Blend {
                anchors.fill: mt
                source: mt
                foregroundSource: mask
                mode: "color"
            }
        }
    }
}
