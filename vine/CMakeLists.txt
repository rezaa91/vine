cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME vine)

project(${PROJECT_NAME})

add_library(
    ${PROJECT_NAME} STATIC
    ${PROJECT_SOURCE_DIR}/src/CollisionManager.cpp
    ${PROJECT_SOURCE_DIR}/src/Entity.cpp
    ${PROJECT_SOURCE_DIR}/src/EntityManager.cpp
    ${PROJECT_SOURCE_DIR}/src/Game.cpp
    ${PROJECT_SOURCE_DIR}/src/Map.cpp
    ${PROJECT_SOURCE_DIR}/src/TextureManager.cpp
    ${PROJECT_SOURCE_DIR}/src/components/ColliderComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/components/SpriteComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/components/TileComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/components/TransformComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/components/VelocityComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/fsm/GameStates.cpp
    ${PROJECT_SOURCE_DIR}/src/input/GameInput.cpp
    ${PROJECT_SOURCE_DIR}/src/input/PlayerInput.cpp
)

message("LOCATION ${PROJECT_SOURCE_DIR}")
target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    tinyxml
    ${PROJECT_SOURCE_DIR}/sdl/SDL2.lib
    ${PROJECT_SOURCE_DIR}/sdl/SDL2main.lib
    ${PROJECT_SOURCE_DIR}/sdl/SDL2_image.lib
)
