import QtQuick 2.15
import QML.Constants
import Qt5Compat.GraphicalEffects

Item {
    id: avatar

    property bool isImage: false
    property bool isNoImage: false
    property string avatarName: ""
    property string sourceImg: ""

    Rectangle {
        width: parent.width
        height: parent.height
        color: UIColors.grey
        anchors.centerIn: parent
        radius: width / 2
        visible: isNoImage

        CustomText {
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: UIColors.white
            textStr: avatarName
        }
    }

    Image {
        id: userImage
        property bool rounded: true
        width: parent.width
        height: parent.height
        visible: isImage
        source: sourceImg

        layer.enabled: rounded
        layer.effect: OpacityMask {
            maskSource: Item {
                width: userImage.width
                height: userImage.height
                Rectangle {
                    anchors.centerIn: parent
                    width: parent.width
                    height: parent.height
                    radius: Math.min(parent.width, parent.height)
                }
            }
        }
    }
}


