import QtQuick 2.0

ListView {
    id: listViewId
    width: parent.width; height: parent.height
    clip: true
    model: musicPlayListModel
    delegate:
    Rectangle {
        width: listViewId.width; height: listViewId.height/10

        Text {
            text: modelData.name
            x: parent.width/10;
            anchors.verticalCenter: parent.verticalCenter
            color: "black"
            font.pixelSize: parent.height/3
        }

        MouseArea {
            anchors.fill: parent
            onPressed: parent.color = "#d5d5d5"
            onReleased: parent.color = "white"
            onCanceled: parent.color = "white"
            onClicked: musicPlayListModel.setCurrentPlayMusicId(modelData.id)
        }

        Rectangle {
            anchors.bottom: parent.bottom
            x: parent.width/10
            width: parent.width; height: 1
            color: "#d5d5d5"
        }
    }
}
