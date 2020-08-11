message("Creating testing build")
cmake_minimum_required(VERSION 3.17)

set(PROJECT_NAME test)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} test.cpp)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    gtest_main
)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)
