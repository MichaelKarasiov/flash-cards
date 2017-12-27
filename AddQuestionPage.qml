import QtQuick 2.6
import QtQuick.Controls 2.1
import Tester 1.0
import "BasicElements" as Element
Item{
id: qu_page
anchors.fill: parent
visible: false
onVisibleChanged: window.title = MainActivity.getCurrentTopicName()
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
        wrapMode: Text.WordWrap
    }
    TextArea
    {
        id: q_answer
        height: q_text.height
        width: parent.width
        placeholderText: "Answer"
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Qt.AlignHCenter
        wrapMode: Text.WordWrap
    }
    Button
    {
        id: accept_q_button
        height: q_title.height
        width: parent.width / 3
        text: "Save"
        highlighted: true

        anchors.horizontalCenter: parent.horizontalCenter

        onClicked:
        {
            if(MainActivity.add_q_data(q_title.text, q_text.text, q_answer.text))
            {
                console.log("adding question")
                q_title.clear()
                q_text.clear()
                q_answer.clear()
                stackView.pop()
            }
            else window.color = "red"
        }
    }

}
}
