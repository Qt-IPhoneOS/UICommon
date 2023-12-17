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
    opacity: enableAnimation ? UIAligns.opacity_0 : UIAligns.opacity_1

    PropertyAnimation {
        id: fadeInAnimation
        target: text
        property: "opacity"
        from: UIAligns.opacity_0
        to: UIAligns.opacity_1
        duration: enableAnimation ? UIAligns.duration_400 : UIAligns.duration_0
    }

    PropertyAnimation {
        id: fadeOutAnimation
        target: text
        property: "opacity"
        from: UIAligns.opacity_1
        to: UIAligns.opacity_0
        duration: enableAnimation ? UIAligns.duration_400 : UIAligns.duration_0
    }

    onVisibleAnimationChanged: {
        visibleAnimation ? fadeInAnimation.start() : fadeOutAnimation.start()
    }
}
