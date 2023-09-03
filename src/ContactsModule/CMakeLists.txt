project(ContactsModule)

set(CPP_SOURCES contact.cpp contactsmodel.cpp clientmanager.cpp contactsworker.cpp)

add_library(${PROJECT_NAME} STATIC ${CPP_SOURCES})

target_sources(${PROJECT_NAME} PRIVATE
    include/contact.h
    include/contactsmodel.h
    include/clientmanager.h
    include/contactsworker.h
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Quick
    DBManager
    NetworkLib
)

