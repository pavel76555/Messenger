import QtQuick 2.15
import Contacts 1.0

BaseListView {
    id: root
    model: ContactsModel {

    }

    delegate: ContactDelegate {
        width: root.width
        height: root.height / 8
    }
}
