cmake_minimum_required(VERSION 3.26.4)

project(Gigantes)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(SFML COMPONENTS graphics system window)

add_executable(Gigantes 
    ${SRC_DIR}/main.cpp
)

target_include_directories(Gigantes PRIVATE ${INCLUDE_DIR})

target_link_libraries(Gigantes PRIVATE sfml-graphics)

target_link_directories(Gigantes PUBLIC ${INCLUDE_DIR})