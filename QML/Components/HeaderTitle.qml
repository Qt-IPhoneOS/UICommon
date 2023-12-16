import QtQuick 2.15
import QtQuick.Controls 2.15
import QML.Constants

Item {
    id: content
    property string textStr: ""

    Text {
        color: UIColors.black
        font {
            pixelSize: 30
            weight: 600
            family: "Helvetica"
        }
        text: textStr
    }
}
