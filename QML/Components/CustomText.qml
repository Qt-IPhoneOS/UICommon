import QtQuick 2.15
import QML.Constants

Text {
    id: text

    property int fontSize: UIFonts.small_pixel
    property string fontFamily: "Helvetica"
    property int fontWeight: UIFonts.light_weight
    property string textStr: ""
    property bool enableAnimation: false
    property bool visibleAnimation: false

    font {
        pixelSize: fontSize
        family: fontFamily
        weight: fontWeight
    }

    text: textStr
    color: UIColors.black
}
