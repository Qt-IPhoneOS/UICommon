import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: underline
    width: parent.width - marginValue
    height: 1
    anchors.left: parent.left
    anchors.leftMargin: marginValue
    color: "#e3e3e3"

    property int marginValue
}
