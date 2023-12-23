import QtQuick 2.15
import QML.Constants

Rectangle {
    width: 30
    height: 30
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
