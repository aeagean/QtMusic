import QtQuick 2.5

Canvas {
    id: canvasId
    property color triangleColor: "#474747"
    width: parent.width; height: parent.height
    contextType: "2d"

    onPaint: {
        context.lineWidth = 0
        context.strokeStyle = "#00000000"
        context.fillStyle = triangleColor
        context.beginPath();
        context.moveTo(0, 0)
        context.lineTo(0, canvasId.height);
        context.lineTo(canvasId.width, canvasId.height/2);
        context.closePath();
        context.fill()
        context.stroke();
    }
}
