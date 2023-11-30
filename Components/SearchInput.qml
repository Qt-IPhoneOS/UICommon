import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: searchContainer
    width: parent.width
    height: 35
    anchors {
        top: headerContact.bottom
        topMargin: 20
        horizontalCenter: parent.horizontalCenter
    }
    color: "#DCDCDC"
    radius: 10

    Image {
        id: searchIcon
        width: 25
        height: 25
        anchors {
            left: parent.left
            leftMargin: 5
            verticalCenter: parent.verticalCenter
        }

        source: "qrc:/Assets/search_icon.png"
        MouseArea {
            anchors.fill: parent
            onClicked: {

            }
        }
    }

    TextField {
        id: textInput
        placeholderText: "Search"
        placeholderTextColor: "#7F7F81"
        width: parent.width - 60
        height: parent.height
        color: "#000000"
        anchors {
            horizontalCenter: parent.horizontalCenter
        }
        background: Item {
            anchors.fill: parent
            Rectangle {
                anchors.fill: parent
                color: "transparent"
            }
        }
        onAccepted: {
        }
    }

    Image {
        id: deleteTextInputButton
        width: 15
        height: 15
        visible: textInput.cursorPosition >= 1
        source: "qrc:/Assets/delete_icon.png"
        anchors {
            right: parent.right
            rightMargin: 5
            verticalCenter: parent.verticalCenter
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                textInput.text = ""
            }
        }
    }
}
