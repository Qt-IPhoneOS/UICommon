import QtQuick 2.15

Text {
    id: text

    QtObject {
        id: constant

        readonly property int smallest: 12
    }

    property string fontFamily: "Helvetica"
    property int fontWeight: 300
    property string textStr: ""
    property string type: "smallest"

    font {
        pixelSize: {
            if (type == "smallest")
                return constant.smallest
        }

        family: fontFamily
        weight: fontWeight
    }

    text: textStr
}
