import QtQuick 2.0

ListView {
    id: listViewId
    width: parent.width; height: parent.height
    clip: true
    model: musicPlayListModel
    delegate:
    Rectangle {
        width: listViewId.width; height: listViewId.height/8


        Text {
            text: modelData.name
            x: parent.width/20;
            anchors.verticalCenter: parent.verticalCenter
            color: "black"
            font.pixelSize: parent.height/3
        }

        MouseArea {
            anchors.fill: parent
            onClicked: musicPlayListModel.setCurrentPlayMusicId(modelData.id)
        }
    }
}
