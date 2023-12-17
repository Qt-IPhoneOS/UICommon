import QtQuick 2.15
import QtQuick.Controls 2.15
import QML.Constants

Item {
    id: content
    property string textStr: ""

    CustomText {
        color: UIColors.black
        fontSize: UIFonts.biggest_pixel
        fontWeight: UIFonts.bold_weight
        textStr: content.textStr
    }
}
