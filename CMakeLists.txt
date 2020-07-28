message("-- Creating build...")
cmake_minimum_required(VERSION 3.17)

# variables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE debug32)

set(PROJECT_NAME game_engine)
set(VERSION 1.0)

# project
message("-- ${PROJECT_NAME} VERSION ${VERSION}")
project(${PROJECT_NAME} VERSION ${VERSION})

# include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/vendor/SDL2/includes/
    ${PROJECT_SOURCE_DIR}/vendor/SDL2_Image/includes/
    ${PROJECT_SOURCE_DIR}/vendor/tinyxml
    ${PROJECT_SOURCE_DIR}/vendor/spdlog/include
    ${PROJECT_SOURCE_DIR}/vendor/glm
)

# link_directories
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/tinyxml)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/spdlog)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/glm/glm)

# executable
message("-- Creating executable")
add_executable(
    ${PROJECT_NAME} 
    src/main.cpp
)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC 
    ${PROJECT_SOURCE_DIR}/vendor/SDL2/lib/SDL2.lib 
    ${PROJECT_SOURCE_DIR}/vendor/SDL2/lib/SDL2main.lib
    ${PROJECT_SOURCE_DIR}/vendor/SDL2_Image/lib/SDL2_image.lib
    tinyxml
)
