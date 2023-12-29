import QtQuick 2.15
import QML.Constants

Rectangle {
    id: header

    width: parent.width
    height: constant.header_height
    z: 10
    color: UIColors.screen_background

    property string backBtnText: ""
    property string headerText: ""
    property string rightText: ""
    property bool isBackButton: true
    property bool enableHeader: false

    states: [
        State {
            name: "HeaderEnabled"
            when: header.enableHeader

            PropertyChanges { target: header; color: UIColors.light_greyish }
            PropertyChanges { target: underline; color: UIColors.light_grey }
        },
        State {
            name: "HeaderDisabled"
            when: !header.enableHeader

            PropertyChanges { target: header; color: UIColors.screen_background }
            PropertyChanges { target: underline; color: UIColors.screen_background }
        }
    ]

    transitions: [
        Transition {
            ColorAnimation { properties: "color"; duration: 300 }
        }
    ]

    signal back()

    QtObject {
        id: constant
        readonly property int horizontal_align: 16
        readonly property int header_height: 60
    }

    BackButton {
        id: backBtn
        visible: isBackButton
        previousText.text: backBtnText
        y: 25
        anchors {
            left: parent.left
            leftMargin: constant.horizontal_align
        }
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

    CustomText {
        text: rightText
        visible: text !== ""
        width: parent.width
        font.weight: Font.Light
        color: UIColors.blue
        anchors {
            left: parent.right
            rightMargin: constant.horizontal_align
        }
    }

    Underline {
        id: underline
        width: parent.width
        anchors.top: header.bottom
        color: UIColors.screen_background
    }
}
