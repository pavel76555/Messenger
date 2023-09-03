import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("AddressBook")

    Style {
        id: _style
    }

    ContactsView {
        anchors.fill: parent
    }


    Rectangle {
        id: _background
        z: -100
        anchors.fill: parent
        color: _style.backgroundColor
        opacity: _style.emphasisOpacity
    }


}
