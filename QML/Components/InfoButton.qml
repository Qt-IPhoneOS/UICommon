import QtQuick 2.15
import QML.Constants

Rectangle {
    width: 25
    height: 25
    radius: width / 2
    border.color: UIColors.blue

    CustomText {
        anchors.centerIn: parent
        textStr: "i"
        fontFamily: "Courier"
        color: UIColors.blue
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
