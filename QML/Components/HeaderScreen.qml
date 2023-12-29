import QtQuick 2.15
import QML.Constants

Item {
    id: headerItem

    width: parent.width
    height: constant.header_height

    property string backBtnText: ""
    property string headerText: ""
    property bool isBackButton: true

    property bool isFlick: false

    signal back()

    QtObject {
        id: constant
        readonly property int horizontal_align: 16
        readonly property int header_height: 45
    }

    Rectangle {
        anchors.fill: parent
        color: headerItem.isFlick ? "#ffffff" : "#f0f2f5"
    }

    BackButton {
        id: backBtn
        anchors {
            verticalCenter: parent.verticalCenter
        }
        visible: isBackButton
        previousText.text: backBtnText
        onBack: headerItem.back()

    }

    CustomText {
        text: headerText
        visible: text !== ""
        width: parent.width
        fontSize: UIFonts.medium_pixel
        fontWeight: Font.Bold
        horizontalAlignment: Text.AlignHCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    Underline {
        width: parent.width
        visible: headerItem.isFlick
        anchors {
            bottom: parent.bottom
        }
    }
}
