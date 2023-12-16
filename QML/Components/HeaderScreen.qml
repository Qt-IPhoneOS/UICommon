import QtQuick 2.15

Rectangle {
    id: header
    y: 30
    property string backBtnText: ""
    property string headerText: ""
    property bool isBackButton: true
    color: "transparent"

    signal back()

    BackButton {
        id: backBtn
        visible: isBackButton
        previousText.text: backBtnText

        onBack: header.back()
    }

    Text {
        text: headerText
        visible: text !== ""
        width: parent.width
        horizontalAlignment: Text.AlignHCenter
        font {
            pixelSize: 20
            weight: Font.Bold
        }
    }
}
