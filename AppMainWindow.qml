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
    signal mainShowContentButtonClicked
    signal mainAddContentButtonClicked
    signal mainDeleteButtonClicked
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
            id: optionBar
            ToolButton {
                id: mainShowContentButton
                visible: stackView.depth > 1
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source:  "images/back.png"
                }
                onClicked: {
                    stackView.pop()
                }
            }
            ToolButton {
                id: mainAddContentButton
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "images/drawer.png"
                }
                onClicked: {
                    mainAddContentButtonClicked()
                }
            }

            ToolButton {
                id: mainDeleteButton
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "images/menu.png"
                }
                onClicked: {
                    stackView.push(q_page);
                    parent.visible = false;
                }
                //                    onClicked: optionsMenu.open()

                //                    Menu {
                //                        id: optionsMenu
                //                        x: parent.width - width
                //                        transformOrigin: Menu.TopRight

                //                        MenuItem {
                //                            text: "Settings"
                //                            onTriggered: settingsDialog.open()
                //                        }
                //                        MenuItem {
                //                            text: "About"
                //                            onTriggered: aboutDialog.open()
                //                        }
                //                    }
            }
        }
    }



    StackView {
        id: stackView
        anchors.fill: parent
        initialItem:
            TopicPage
        {
            id: topicPage
            onAddClicked: {
                stackView.push(q_page)
                mainShowContentButton.visible = true
            }
            anchors.fill: parent
        }
    }
    AddQuestionPage{id: q_page}
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
