cmake_minimum_required(VERSION 3.16)

project(Messenger VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Quick
        Qml
        Sql
        Widgets
        REQUIRED
)

qt_standard_project_setup()

add_subdirectory(src/)


set_target_properties(Messenger PROPERTIES
MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
MACOSX_BUNDLE TRUE
WIN32_EXECUTABLE TRUE
)


install(TARGETS Messenger
BUNDLE DESTINATION .
LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
        
