cmake_minimum_required(VERSION 3.26.4)

project(ODISSEIA_TEMPORALIS)

find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}../../)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/**/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp" "include/**/*.hpp")

add_executable(${PROJECT_NAME}  ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

file(GLOB_RECURSE TEST_SOURCES "testes/*.cpp" "testes/**/*.cpp")

add_executable(testes ${TEST_SOURCES} ${SOURCES} ${HEADERS})
target_link_libraries(testes ${GTEST_BOTH_LIBRARIES} pthread)
target_link_libraries(testes sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/src")
target_include_directories(testes PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/src")

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
target_link_libraries(testes sfml-system sfml-window sfml-graphics sfml-network sfml-audio)