cmake_minimum_required(VERSION 4.3)

project(main)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(SRC "src")

add_definitions(-w)

find_package(json-c CONFIG)

include_directories(include)
include_directories(${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME} 
    ${SRC}/main.c
    ${SRC}/io/requesthttp.c
    ${SRC}/linkedlist/linkedlist.c
    ${SRC}/process/processwrapper.c
    ${SRC}/thread/threadwrapper.c
)

target_link_libraries(${PROJECT_NAME}
        -lcurl
        -ljson-c
        -lmariadb
        -lpthread
        json-c::json-c)
