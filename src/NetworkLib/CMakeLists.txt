project(NetworkLib)

set(CPP_SOURCES package.cpp connectionargumentsparser.cpp)

add_library(${PROJECT_NAME} STATIC ${CPP_SOURCES})

target_sources(${PROJECT_NAME} PRIVATE
    include/package.h
    include/networktypes.h
    include/connectionargumentsparser.h
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE Qt6::Network
    # PRIVATE Qt6::Sql
)

