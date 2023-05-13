import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import Qt.labs.platform

Window {
    id: window

    width: 100
    height: 100
    visible: true
    opacity: 0.9
    color: "#515c6b"
    flags: Qt.FramelessWindowHint | Qt.WA_TranslucentBackground

    BatteryLevelIndicator {
        anchors.fill: parent

        batteryLevel: razerMouse.batteryLevel
        isCharging: razerMouse.isCharging

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.RightButton

            onClicked: {
                menu.open()
            }
        }

        Menu {
            id: menu

            MenuItem {
                text: "Exit"

                onTriggered: {
                    Qt.quit()
                }
            }
        }
    }

    DragHandler {
        onActiveChanged: {
            if (active) {
                window.startSystemMove()
            }
        }
    }

    Timer {
        interval: 1000
        running: true
        repeat: true
        triggeredOnStart: true

        onTriggered: {
            razerMouse.update()
        }
    }

    RazerMouseBattery {
        id: razerMouse

        commandPath: "C:/Users/anton/Projects/my/razer-mouse-battery/bin/RelWithDebInfo/razer-mouse-battery.exe"
    }
}
