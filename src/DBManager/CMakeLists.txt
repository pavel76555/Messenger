project(DBManager)

set(CPP_SOURCES Executor.cpp Selector.cpp Processor.cpp ConnectionManager.cpp Manipulator.cpp)

add_library(${PROJECT_NAME} STATIC ${CPP_SOURCES})

target_sources(${PROJECT_NAME} PRIVATE
    include/dbtypes.h
    include/dbmapper.h
    include/Executor.h
    include/Selector.h
    include/Processor.h
    include/Manipulator.h
    include/ConnectionManager.h
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Sql
)

