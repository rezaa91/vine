message("-- Creating build...")
cmake_minimum_required(VERSION 3.17)

# variables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE debug32)
set(PROJECT_NAME game_engine)
project(${PROJECT_NAME})

set(PROJECT_NAME game_engine)

# include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/vine/src
    ${PROJECT_SOURCE_DIR}/vendor/SDL2/includes/
    ${PROJECT_SOURCE_DIR}/vendor/SDL2_Image/includes/
    ${PROJECT_SOURCE_DIR}/vendor/tinyxml
    ${PROJECT_SOURCE_DIR}/vendor/spdlog/include
    ${PROJECT_SOURCE_DIR}/vendor/glm
    ${PROJECT_SOURCE_DIR}/vendor/googletest/googletest/include
    ${PROJECT_SOURCE_DIR}/vendor/glm/googletest/googlemock/include
)

# link_directories
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/tinyxml)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/spdlog)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/glm/glm)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/googletest)
add_subdirectory(${PROJECT_SOURCE_DIR}/vine)
add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
add_subdirectory(${PROJECT_SOURCE_DIR}/game)

# copy assets dir to binary location
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
