
import QtQuick 2.6
import QtQuick.Controls 2.1
import Tester 1.0
import "BasicElements" as Element
Item
{
    anchors.fill: parent
    signal addClicked;
    property int currIndex: -1
    //    Rectangle{
    //        anchors.fill: parent
    //        anchors.top: parent.top
    //        anchors.bottom: add_Topic_b.top
    //        anchors.left: parent.left
    //        anchors.right: parent.right

    //color: "red"

//    Item {
//        id: optionBar
//        visible:false
//        width: lsv.width
//        x: lsv_delegate.x
//        z: lsv.z + 1
//        Rectangle {
//            width: parent.width / 4
//            height: width
//            radius: width
//            color: "green"
//            Text {
//            anchors.centerIn: parent
//            text: "+"
//            }
//            MouseArea {
//            anchors.fill: parent
//            onClicked: addClicked()
//            }
//        }
//    }
    ListView{
        id:lsv
        //anchors.fill: parent
        clip: true
        model: MainActivity.topicsModel
        height: parent.height * 0.8
        width: parent.width
        delegate:
            Button
        {
            id: lsv_delegate
            text: model.name_ + " (" + model.count_ + ")"
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width * 0.8
            height: 50
            highlighted: false
            onClicked: {
                currIndex = model.index
                console.log("Selected tpic index : " + model.index);
                MainActivity.set_current_topic(model.index)
                optionBar.visible = true
                highlighted = true
                //addClicked()
            }
            onFocusChanged: {
                optionBar.visible = false
                highlighted = false
        }
    }
    }

    Button {
        id: add_Topic_b
        height: lsv.delegate.height
        width: parent.width /3
        text: "+"
        highlighted: true

        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: height/2

        onClicked: add_topic_dialog.open()
    }
    Dialog
    {
        id: add_topic_dialog
        height: parent.width * 0.5
        width: height
        title: "Add topic"
        leftMargin: (parent.width - width)/2
        TextField
        {
            id: text_topic_name
            height: parent.header.height * 1.3
            width: parent.width * 0.8
            anchors.top: parent.header.bottom
            anchors.topMargin: height/2
        }

        Button
        {
            text: "Ok"
            width: parent.width * 0.6

            height: text_topic_name.height * 1.3
            anchors.top: text_topic_name.bottom
            anchors.topMargin: height/3

            onClicked: {
                if(text_topic_name.text != ""){
                    MainActivity.add_topic(text_topic_name.text)
                    add_topic_dialog.accept();
                    //TODO setTopic
                    addClicked();
                }
            }
        }

    }
}
