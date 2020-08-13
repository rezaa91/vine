message("Creating testing build")
cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME test)
project(${PROJECT_NAME})

add_executable(
    ${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/vine/GameTest.cpp
)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    vine
    gtest_main
)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)
