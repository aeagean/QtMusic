import QtQuick 2.0

Rectangle {
    id: rectId
    width: parent.width; height: parent.height
    color: "#f2f2f2"


    ListView {
        id: listViewId
        width: parent.width; height: parent.height
        clip: true
        orientation: ListView.Horizontal
        model: fileBrowserListModel.pathNameList
        header: Item {
            width: headerTextId.width; height: rectId.height

            Text {
                id: headerTextId
                anchors.centerIn: parent
                color: "#474747"
                text: "    "+"disk"+"    >"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: fileBrowserListModel.changedPath(0)
            }
        }
        delegate: Item {
            width: textId.width /*+ 10*/; height: rectId.height

            Text {
                id: textId
                anchors.centerIn: parent
                color: "#474747"
                text: "    "+modelData+"    >"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: fileBrowserListModel.changedPath(index+1)
            }
        }
    }
}
