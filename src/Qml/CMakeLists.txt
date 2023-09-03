project(Qml)

qt_add_qml_module(${PROJECT_NAME}
    URI ${PROJECT_NAME}
    VERSION 1.0
    QML_FILES
        Main.qml
        Style.qml
        BaseText.qml
        BaseListView.qml
        ContactsView.qml
        BaseListDelegate.qml
        ContactDelegate.qml

    RESOURCES 
        img/profile-circle.svg
)
