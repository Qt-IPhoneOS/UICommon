pragma Singleton
import QtQuick 2.15

QtObject {

    /*
      * font weight constants
      */
    readonly property int light_weight: 300
    readonly property int medium_weight: 400
    readonly property int semi_bold_weight: 500
    readonly property int bold_weight: 600

    /*
      * font pixel constants
      */
    readonly property int smallest_pixel: 12
    readonly property int small_pixel: 16
    readonly property int medium_pixel: 20
    readonly property int biggest_pixel: 30
}
