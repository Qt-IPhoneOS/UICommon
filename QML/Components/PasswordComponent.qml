import QtQuick 2.15

Item {
    id: rootItem
    width: 500
    height: 55

    property int marginLeft: 50


    Text {
        text: "Password"
        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
            leftMargin: (marginLeft - width) / 2
        }
    }

    Item {
        width: 200
        height: 20
        anchors {
            verticalCenter: parent.verticalCenter
            right: parent.left
            rightMargin: (marginLeft - width) / 2
        }
        Repeater {
            anchors.fill: parent
            model: 15
            delegate: Rectangle {
                anchors.horizontalCenter: parent.horizontalCenter
                x: model.index *11
                width: 10
                height: 10
                radius: 5
                color: "gray"
            }
        }
    }
}
