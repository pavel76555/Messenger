import QtQuick 2.15

BaseListDelegate {
    id: root

    Rectangle {
        id: _imageBubble
        width: root.height - 15
        height: root.height - 15
        anchors.left: root.left
        anchors.leftMargin: _style.tinyOffset
        anchors.verticalCenter: root.verticalCenter
        color: _style.backgroundColor
        border.color: _style.primaryColor
        border.width: 2
        radius: width*0.5

        Image {
            anchors.fill: parent
            anchors.margins: 8
            source: "img/profile-circle.svg"
        }
    }

    Column {
        anchors.verticalCenter: root.verticalCenter
        anchors.left : _imageBubble.right
        anchors.leftMargin: _style.defaultOffset
        Row {
            spacing: _style.smallSpacing
            BaseText {
                text: firstName
            }
            BaseText {
                text: secondName
            }
        }

        BaseText {
            text: "+" + phoneNumber
            color: _style.primaryColor
        }
    }
}
