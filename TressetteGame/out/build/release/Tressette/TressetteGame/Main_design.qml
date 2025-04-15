import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    id: appRoot
    anchors.fill: parent
    focus: true
    antialiasing: false
    width: 1920
    height: 1080

    property real baseWidth: 1920
    property real baseHeight: 1080
    property real scaleFactor: Math.min(width / baseWidth, height / baseHeight)

    signal playClicked
    signal rulesClicked
    signal exitClicked
    

    Rectangle {
        anchors.fill: parent
        color: "#1e2a38"
        gradient: Gradient {
            GradientStop {
                position: 0.0
                color: "#2c3e50"
            }
            GradientStop {
                position: 1.0
                color: "#34495e"
            }
        }

        ColumnLayout {
            id: mainLayout
            anchors.centerIn: parent
            spacing: 50 * appRoot.scaleFactor

            // Title
            Item {
                width: titleText.width + 6 * appRoot.scaleFactor
                height: titleText.height + 6 * appRoot.scaleFactor
                Layout.alignment: Qt.AlignHCenter

                Text {
                    id: titleShadow
                    text: "Tressette Game"
                    font.pixelSize: 64 * appRoot.scaleFactor
                    font.bold: true
                    color: "#000000"
                    opacity: 0.4
                    x: 3 * appRoot.scaleFactor
                    y: 3 * appRoot.scaleFactor
                }

                Text {
                    id: titleText
                    text: "Tressette Game"
                    font.pixelSize: 64 * appRoot.scaleFactor
                    font.bold: true
                    color: "#ecf0f1"
                    anchors.centerIn: parent
                }
            }

            // PLAY BUTTON
            Rectangle {
                width: 300 * appRoot.scaleFactor
                height: 70 * appRoot.scaleFactor
                radius: 16 * appRoot.scaleFactor

                property bool hovered: false
                property bool pressed: false

                color: hovered ? "#1abc9c" : "#16a085"
                border.color: Qt.darker(color, 1.2)
                border.width: pressed ? 3 : 2

                Behavior on color {
                    ColorAnimation {
                        duration: 200
                    }
                }
                Behavior on border.width {
                    NumberAnimation {
                        duration: 150
                    }
                }

                Text {
                    text: "Play"
                    anchors.centerIn: parent
                    font.pixelSize: 24 * appRoot.scaleFactor
                    font.bold: true
                    color: "white"
                }

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true

                    onEntered: parent.hovered = true
                    onExited: parent.hovered = false

                    onPressed: parent.pressed = true

                    onReleased: parent.pressed = false
                    //appRoot.playClicked();
                }
            }

            // RULES BUTTON
            Rectangle {
                width: 300 * appRoot.scaleFactor
                height: 70 * appRoot.scaleFactor
                radius: 16 * appRoot.scaleFactor

                property bool hovered: false
                property bool pressed: false

                color: hovered ? "#3498db" : "#2980b9"
                border.color: Qt.darker(color, 1.2)
                border.width: pressed ? 3 : 2

                Behavior on color {
                    ColorAnimation {
                        duration: 200
                    }
                }
                Behavior on border.width {
                    NumberAnimation {
                        duration: 150
                    }
                }

                Text {
                    text: "Rules"
                    anchors.centerIn: parent
                    font.pixelSize: 24 * appRoot.scaleFactor
                    font.bold: true
                    color: "white"
                }

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true

                    onEntered: parent.hovered = true

                    onExited: parent.hovered = false

                    onPressed: parent.pressed = true

                    onReleased: parent.pressed = false
                    //appRoot.rulesClicked();
                }
            }

            // EXIT BUTTON
            Rectangle {
                width: 300 * appRoot.scaleFactor
                height: 70 * appRoot.scaleFactor
                radius: 16 * appRoot.scaleFactor

                property bool hovered: false
                property bool pressed: false

                color: hovered ? "#e74c30" : "#C03920"
                border.color: Qt.darker(color, 1.2)
                border.width: pressed ? 3 : 2

                Behavior on color {
                    ColorAnimation {
                        duration: 200
                    }
                }
                Behavior on border.width {
                    NumberAnimation {
                        duration: 150
                    }
                }

                Text {
                    text: "Exit"
                    anchors.centerIn: parent
                    font.pixelSize: 24 * appRoot.scaleFactor
                    font.bold: true
                    color: "white"
                }

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true

                    onEntered: parent.hovered = true

                    onExited: parent.hovered = false

                    onPressed: parent.pressed = true

                    onReleased: parent.pressed = false
                    //  appRoot.exitClicked();
                }
            }
        }
    } 
    
}
