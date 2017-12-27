import QtQuick 2.0

Item {
    id:button
    signal clicked;
    property alias text: t.text
    Rectangle
    {
        anchors.fill: parent
        color: "gray"
        Text {
            id: t
            anchors.centerIn: parent
        }
    }

MouseArea {
anchors.fill: parent
onClicked: button.clicked()
}
}
