import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: root
    visible: true
    width: 1024
    height: 768

    color: "#2e3436"


    Text {
        id: title
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 60
        text: qsTr(_post.title)
        font.pixelSize: 70
        font.bold: true
        color: "#1df94f"
        wrapMode: Text.Wrap
    }

    Rectangle {
        id: separator
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: title.bottom
        anchors.topMargin:  40
        anchors.bottomMargin:  40

        anchors.margins: 4
        height: 8
        color: "#1f9239"

        Rectangle{
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left

            color: "#1df94f"
            width: 0
            NumberAnimation on width{
                id: durationIndicatorAnimation
                running: true
                from: 0
                to: root.width-8
                duration: 10000
                onStopped: {_post.next(); start();}
            }
        }
    }

    Item {
        id: userRow
        anchors.top: separator.bottom
        anchors.left: content.left
        height: childrenRect.height
        anchors.topMargin:  60

        Image{
            id: pic
            source: "https://forum.wilap.de" + _post.avatarUrl
        }
        Text{
            id: username
            text: _post.user
            anchors.leftMargin: 30
            anchors.verticalCenter: pic.verticalCenter
            anchors.verticalCenterOffset: 0.1*height
            anchors.left: pic.right
            font.pixelSize: 40
            font.bold: true
            color: title.color
        }
    }
    Text{
        id: content
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 60

        anchors.top: userRow.bottom
        text: _post.text
        color: "#e4e4ce"
        lineHeight: 1.25
        font.family: "Titillium Semibold"
        wrapMode: Text.Wrap
        font.pixelSize: 20
    }

}
