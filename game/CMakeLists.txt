cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME myGame)
project(${PROJECT_NAME})

include_directories(
    ${PROJECT_SOURCE_DIR}/src
)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    vine
    tinyxml
)
