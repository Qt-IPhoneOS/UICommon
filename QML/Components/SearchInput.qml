import QtQuick 2.15
import QtQuick.Controls 2.15
import QML.Constants

Rectangle {
    id: searchContainer
    width: parent.width
    height: constant.search_input_height
    anchors {
        top: headerContact.bottom
        topMargin: UIAligns.margin_20
        horizontalCenter: parent.horizontalCenter
    }
    color: constant.search_input_color
    radius: constant.search_input_radius

    QtObject {
        id: constant

        readonly property int search_input_height: 35
        readonly property int search_input_radius: 10
        readonly property string search_input_color: "#DCDCDC"

        readonly property int icon_width: 25
        readonly property int icon_height: 25
        readonly property string icon_source: "qrc:/Assets/search_icon.png"

        readonly property int align_value: 60
        readonly property string input_placeholders: "Search"

        readonly property int delete_btn_width: 15
        readonly property int delete_btn_height: 15
        readonly property string delete_source: "qrc:/Assets/delete_icon.png"
    }

    Image {
        id: searchIcon
        width: constant.icon_width
        height: constant.icon_height
        anchors {
            left: parent.left
            leftMargin: UIAligns.margin_5
            verticalCenter: parent.verticalCenter
        }

        source: constant.icon_source
        MouseArea {
            anchors.fill: parent
            onClicked: {

            }
        }
    }

    TextField {
        id: textInput
        placeholderText: constant.input_placeholders
        placeholderTextColor: UIColors.grey
        width: parent.width - constant.align_value
        height: parent.height
        color: UIColors.black
        anchors.horizontalCenter: parent.horizontalCenter

        background: Item {
            anchors.fill: parent
            Rectangle {
                anchors.fill: parent
                color: UIColors.transparent
            }
        }
        onAccepted: {
        }
    }

    Image {
        id: deleteTextInputButton
        width: constant.delete_btn_width
        height: constant.delete_btn_height
        visible: textInput.cursorPosition >= 1
        source: constant.delete_source
        anchors {
            right: parent.right
            rightMargin: UIAligns.margin_5
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
