import QtQuick 2.15

Item {
    id: headerItem

    width: parent.width
    height: 50

    property string backBtnText: ""
    property string headerText: ""
    property bool isBackButton: true

    property bool isFlick: false


    signal back()

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

    Text {
        text: headerText
        visible: text !== ""
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.fill: parent
        font {
            pixelSize: 20
            weight: Font.Bold
        }
    }

    Underline {
        width: parent.width
        visible: headerItem.isFlick
        anchors {
            bottom: parent.bottom
        }
    }
}
