import QtQuick 2.15

Rectangle {
    id: root
    color: _style.backgroundColor
    opacity: _delegateArea.pressed ? _style.secondaryOpacity : _style.emphasisOpacity
    MouseArea {
        id: _delegateArea
        anchors.fill: root
    }

}
