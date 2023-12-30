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

    Item {
        width: parent.width
        height: parent.height - 25
        y: 25

        BackButton {
            id: backBtn
            visible: isBackButton
            previousText.text: backBtnText
            anchors {
                left: parent.left
                leftMargin: 16
            }
            onBack: header.back()

        }

        CustomText {
            id: heading
            y: -2
            text: headerText
            visible: text !== ""
            width: parent.width
            fontWeight: UIFonts.bold_weight
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
        }

        CustomText {
            text: rightText
            visible: text !== ""
            color: UIColors.blue
            verticalAlignment: Text.AlignTop
            anchors {
                right: parent.right
                rightMargin: 25
            }
        }
    }

    Underline {
        id: underline
        width: parent.width
        anchors.top: header.bottom
        color: UIColors.screen_background
    }
}
