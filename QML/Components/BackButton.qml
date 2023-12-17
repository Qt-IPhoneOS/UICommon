import QtQuick 2.15

Item {
    id: backButton
    width: 26 + previousText.width + 8
    height: 26

    property alias previousText: previousText
    signal back()

    Image {
        id: backBtn
        width: 26
        height: parent.height
        source: "qrc:/Assets/back_button.png"
    }

    Text {
        id: previousText
        anchors {
            verticalCenter: parent.verticalCenter
            left: backBtn.right
            leftMargin: 8
        }
        font.pixelSize: 18
        font.weight: Font.Light
        color: "#2196f3"
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: backButton.back()
    }
}
