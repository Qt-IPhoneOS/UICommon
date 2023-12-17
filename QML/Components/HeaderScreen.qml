import QtQuick 2.15
import QML.Constants

Item {
    id: header

    width: parent.width - constant.horizontal_align
    height: constant.header_height

    property string backBtnText: ""
    property string headerText: ""
    property bool isBackButton: true

    signal back()

    QtObject {
        id: constant

        readonly property int horizontal_align: 16
        readonly property int header_height: 30
    }

    BackButton {
        id: backBtn
        visible: isBackButton
        previousText.text: backBtnText
        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
            leftMargin: constant.horizontal_align
        }

        onBack: header.back()
    }

    CustomText {
        textStr: headerText
        visible: textStr !== ""
        width: parent.width
        horizontalAlignment: Text.AlignHCenter
        fontSize: UIFonts.medium_pixel
        fontWeight: Font.Bold
        anchors.verticalCenter: parent.verticalCenter
    }
}
