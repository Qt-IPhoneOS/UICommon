import QtQuick 2.15
import QML.Constants

Item {
    id: backButton
    width: constant.back_btn_width + UIAligns.margin_5 + previousText.contentWidth
    height: constant.back_btn_height

    property alias previousText: previousText

    signal back()

    QtObject {
        id: constant
        readonly property int back_btn_width: 22
        readonly property int back_btn_height: 22
        readonly property string back_btn_source: "qrc:/Assets/back_button.png"
    }

    Image {
        id: backBtn
        width: constant.back_btn_width
        height: parent.height
        source: constant.back_btn_source
        anchors.verticalCenter: parent.verticalCenter
    }

    CustomText {
        id: previousText
        anchors {
            verticalCenter: parent.verticalCenter
            left: backBtn.right
            leftMargin: 8
        }
        font.pixelSize: 18
        font.weight: Font.Light
        color: UIColors.blue
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: backButton.back()
    }
}
