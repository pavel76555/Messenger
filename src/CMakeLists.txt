add_executable(${PROJECT_NAME}
    main.cpp
)

 qt_add_qml_module(${PROJECT_NAME}
     URI ${PROJECT_NAME}
     VERSION 1.0
     QML_FILES
         Qml/BaseListDelegate.qml
         Qml/BaseListView.qml
         Qml/BaseText.qml
         Qml/ContactDelegate.qml
         Qml/ContactsView.qml
         Qml/Style.qml
         Qml/Main.qml

     RESOURCES Qml/img/profile-circle.svg
 )

add_subdirectory(ContactsModule/)
add_subdirectory(DBManager/)
add_subdirectory(NetworkLib/)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE Qt6::Quick
    ContactsModule
)
