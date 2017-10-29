import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Controls.Universal 2.1
import Qt.labs.settings 1.0
import Tester 1.0
ApplicationWindow {
    id: window
    width: 360
    height: 520
    visible: true
    title: "Test yourself"

    Settings {
        id: settings
        property string style: "Material"
    }

    Shortcut {
        sequence: "Esc"
        enabled: stackView.depth > 1
        onActivated: {
            stackView.pop()
            listView.currentIndex = -1
        }
    }

        header: ToolBar {
            Material.foreground: "white"

            RowLayout {
                spacing: 20
                anchors.fill: parent

                ToolButton {
                    contentItem: Image {
                        fillMode: Image.Pad
                        horizontalAlignment: Image.AlignHCenter
                        verticalAlignment: Image.AlignVCenter
                        source: stackView.depth > 1 ? "images/back.png" : "images/drawer.png"
                    }
                    onClicked: {
                        if (stackView.depth > 1) {
                            stackView.pop()
                            listView.currentIndex = -1
                        } else {
                            drawer.open()
                        }
                    }
                }

                Label {
                    id: titleLabel
                    text: listView.currentItem ? listView.currentItem.text : "Gallery"
                    font.pixelSize: 20
                    elide: Label.ElideRight
                    horizontalAlignment: Qt.AlignHCenter
                    verticalAlignment: Qt.AlignVCenter
                    Layout.fillWidth: true
                }

                ToolButton {
                    contentItem: Image {
                        fillMode: Image.Pad
                        horizontalAlignment: Image.AlignHCenter
                        verticalAlignment: Image.AlignVCenter
                        source: "images/menu.png"
                    }
                    onClicked: optionsMenu.open()

                    Menu {
                        id: optionsMenu
                        x: parent.width - width
                        transformOrigin: Menu.TopRight

                        MenuItem {
                            text: "Settings"
                            onTriggered: settingsDialog.open()
                        }
                        MenuItem {
                            text: "About"
                            onTriggered: aboutDialog.open()
                        }
                    }
                }
            }
        }



    StackView {
        id: stackView

        anchors.fill: parent

        initialItem: Rectangle{
            anchors.fill: parent

            Column{
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                spacing: parent.height/20
                anchors.topMargin: parent.height/10
                TextField
                {
                    id: q_title
                    width: parent.width
                    height: parent.height/10
                    placeholderText: "Question Title"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.topMargin: parent.height/10
                    horizontalAlignment: Qt.AlignHCenter
                }

                TextArea
                {
                    id: q_text
                    placeholderText: "Question"
                    width: parent.width
                    //height: (q_title.height + parent.spacing*3 + accept_q_button.height) / 2
                    height: stackView.height/3.3
                    anchors.horizontalCenter: parent.horizontalCenter
                    horizontalAlignment: Qt.AlignHCenter

                }
                TextArea
                {
                    id: q_answer
                    height: q_text.height
                    width: parent.width
                    placeholderText: "Answer"
                    anchors.horizontalCenter: parent.horizontalCenter
                    horizontalAlignment: Qt.AlignHCenter
                }
                Button
                {
                    id: accept_q_button
                    height: q_title.height
                    width: parent.width / 3
                    text: "Save"

                    anchors.horizontalCenter: parent.horizontalCenter

                    onClicked:
                    {
                        if(MainActivity.add_q_data(q_title.text, q_text.text, q_answer.text))
                        {
                            console.log("adding question")
                            q_title.clear()
                            q_text.clear()
                            q_answer.clear()
                        }
                        else window.color = "red"
                    }
                }

            }
        }
    }
    //    Dialog {
    //        id: settingsDialog
    //        x: Math.round((window.width - width) / 2)
    //        y: Math.round(window.height / 6)
    //        width: Math.round(Math.min(window.width, window.height) / 3 * 2)
    //        modal: true
    //        focus: true
    //        title: "Settings"

    //        standardButtons: Dialog.Ok | Dialog.Cancel
    //        onAccepted: {
    //            settings.style = styleBox.displayText
    //            settingsDialog.close()
    //        }
    //        onRejected: {
    //            styleBox.currentIndex = styleBox.styleIndex
    //            settingsDialog.close()
    //        }

    //        contentItem: ColumnLayout {
    //            id: settingsColumn
    //            spacing: 20

    //            RowLayout {
    //                spacing: 10

    //                Label {
    //                    text: "Style:"
    //                }

    //                ComboBox {
    //                    id: styleBox
    //                    property int styleIndex: -1
    //                    model: ["Default", "Material", "Universal"]
    //                    Component.onCompleted: {
    //                        styleIndex = find(settings.style, Qt.MatchFixedString)
    //                        if (styleIndex !== -1)
    //                            currentIndex = styleIndex
    //                    }
    //                    Layout.fillWidth: true
    //                }
    //            }

    //            Label {
    //                text: "Restart required"
    //                color: "#e41e25"
    //                opacity: styleBox.currentIndex !== styleBox.styleIndex ? 1.0 : 0.0
    //                horizontalAlignment: Label.AlignHCenter
    //                verticalAlignment: Label.AlignVCenter
    //                Layout.fillWidth: true
    //                Layout.fillHeight: true
    //            }
    //        }
    //    }

    //    Dialog {
    //        id: aboutDialog
    //        modal: true
    //        focus: true
    //        title: "About"
    //        x: (window.width - width) / 2
    //        y: window.height / 6
    //        width: Math.min(window.width, window.height) / 3 * 2
    //        contentHeight: aboutColumn.height

    //        Column {
    //            id: aboutColumn
    //            spacing: 20

    //            Label {
    //                width: aboutDialog.availableWidth
    //                text: "The Qt Quick Controls 2 module delivers the next generation user interface controls based on Qt Quick."
    //                wrapMode: Label.Wrap
    //                font.pixelSize: 12
    //            }

    //            Label {
    //                width: aboutDialog.availableWidth
    //                text: "In comparison to the desktop-oriented Qt Quick Controls 1, Qt Quick Controls 2 "
    //                    + "are an order of magnitude simpler, lighter and faster, and are primarily targeted "
    //                    + "towards embedded and mobile platforms."
    //                wrapMode: Label.Wrap
    //                font.pixelSize: 12
    //            }
    //        }
    //    }
}
