import QtQuick 2.15
import QML.Constants

Text {
    id: text

    property int fontSize: UIConstants.small_pixel
    property string fontFamily: "Helvetica"
    property int fontWeight: UIConstants.light_weight
    property string textStr: ""
    property bool enableAnimation: false
    property bool visibleAnimation: false

    font {
        pixelSize: fontSize
        family: fontFamily
        weight: fontWeight
    }

    text: textStr
    opacity: enableAnimation ? UIConstants.opacity_0 : UIConstants.opacity_1

    PropertyAnimation {
        id: fadeInAnimation
        target: text
        property: "opacity"
        from: UIConstants.opacity_0
        to: UIConstants.opacity_1
        duration: enableAnimation ? UIConstants.duration_400 : UIConstants.duration_0
    }

    PropertyAnimation {
        id: fadeOutAnimation
        target: text
        property: "opacity"
        from: UIConstants.opacity_1
        to: UIConstants.opacity_0
        duration: enableAnimation ? UIConstants.duration_400 : UIConstants.duration_0
    }

    onVisibleAnimationChanged: {
        visibleAnimation ? fadeInAnimation.start() : fadeOutAnimation.start()
    }
}
