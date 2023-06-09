import QtQuick
import QtQuick.Controls
import QtQuick.Shapes

Item {
    id: root

    property bool isOk: false
    property string reason: ""
    property real batteryLevel: 0
    property bool isCharging: false

    property real radius: Math.min(width, height) * 0.4

    layer.enabled: true
    layer.samples: 8

    Shape {
        anchors.fill: parent
        visible: isOk

        ShapePath {
            fillColor: "transparent"
            strokeWidth: root.radius * 0.15
            strokeColor: batteryLevel < 10 ? "red" : batteryLevel < 20 ? "yellow" : "limegreen"
            capStyle: ShapePath.RoundCap
            joinStyle: ShapePath.RoundJoin

            PathAngleArc {
                centerX: root.width * 0.5
                centerY: root.height * 0.5
                radiusX: root.radius
                radiusY: root.radius

                startAngle: -90
                sweepAngle: batteryLevel / 100 * 360
            }
        }
    }

    Label {
        color: "white"
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        font.pointSize: root.radius * 0.3
        fontSizeMode: Text.Fit
        wrapMode: Text.WordWrap

        text: isOk ? (batteryLevel.toFixed(1) + " %" + (isCharging ? "\n⚡" : "")) : reason
    }
}
