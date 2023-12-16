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
    readonly property int biggest_pixel: 30

    /*
      * margin constants
      */
    readonly property int margin_top_20: 20

    /*
      * opacity constants
      */
    readonly property int opacity_0: 0
    readonly property double opacity_05: 0.5
    readonly property int opacity_1: 1

    /*
      * duration constants
      */
    readonly property int duration_0: 0
    readonly property int duration_200: 200
    readonly property int duration_400: 400

    /*
      * detail constants
      */
    readonly property int screen_width: 600
    readonly property int screen_height: 900
}
