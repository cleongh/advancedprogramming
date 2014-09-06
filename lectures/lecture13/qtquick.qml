import QtQuick 1.0
 
// qmlviewer

Rectangle {
    width: 300
    height: 300
    color: "blue"

    Text {
            x: 0; y: frameSize - bottomMargin
            text: "Cotton Grass"
            font.pixelSize: fontSize
            width: frameSize; horizontalAlignment: Text.AlignHCenter
            height: bottomMargin; verticalAlignment: Text.AlignVCenter
        }
}

