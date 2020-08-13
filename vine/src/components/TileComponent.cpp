#include "TileComponent.h"
#include "TextureManager.h"
#include "Game.h"
#include <spdlog/spdlog.h>
#include <SDL2_Image/SDL_image.h>

Vine::TileComponent::TileComponent(
    SDL_Renderer& renderer,
    const int type,
    const int x,
    const int y,
    const int width,
    const int height
    )
    : _renderer(renderer),
    _position({x, y}),
    _width(width),
    _height(height)
{
    switch (static_cast<Vine::TILE_TYPE>(type))
    {
        case Vine::TILE_TYPE::GRASS_LEFT:
            _tileTexture = Vine::TextureManager::getTexture("left_grass");
            break;
        case Vine::TILE_TYPE::GRASS_CENTER:
            _tileTexture = Vine::TextureManager::getTexture("center_grass");
            break;
        case Vine::TILE_TYPE::GRASS_RIGHT:
            _tileTexture = Vine::TextureManager::getTexture("right_grass");
            break;
        case Vine::TILE_TYPE::BLOCK:
            _tileTexture = Vine::TextureManager::getTexture("block");
            break;
    }

    _srcRect = {0, 0, width, height};
    _destRect = {x, y, width, height};
}

SDL_Rect Vine::TileComponent::getRect() const
{
    return _destRect;
}

glm::vec2 Vine::TileComponent::getPosition() const
{
    return _position;
}


void Vine::TileComponent::update(float deltaTime)
{
    _destRect.x = _position.x - Game::_camera.x;
}

void Vine::TileComponent::render()
{
    SDL_RenderCopy(&_renderer, _tileTexture, &_srcRect, &_destRect);
}
