#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "VelocityComponent.h"
#include "../Game.h"
#include "TextureManager.h"
#include <SDL2_Image/SDL_image.h>
#include <spdlog/spdlog.h>

Vine::SpriteComponent::SpriteComponent(
    SDL_Renderer& renderer,
    const std::string textureName,
    const int x,
    const int y,
    const int width,
    const int height,
    const int numberOfFrames,
    const int speed
)
    : _renderer(renderer),
    _width(width),
    _height(height),
    _numberOfFrames(numberOfFrames),
    _speed(speed)
{
    _texture = Vine::TextureManager::getTexture(textureName);
    _srcRect = {0, 0, width, height};
    _destRect = {x, y, width, height};
}

void Vine::SpriteComponent::setFlipped(bool flipped)
{
    if (flipped)
    {
        _flipped = SDL_FLIP_HORIZONTAL;
    }
    else
    {
        _flipped = SDL_FLIP_NONE;
    }
}

SDL_Rect Vine::SpriteComponent::getRect() const
{
    return _destRect;
}

void Vine::SpriteComponent::update(float deltaTime)
{
    Vine::VelocityComponent* spriteVelocityComponent = _owner->getComponent<Vine::VelocityComponent>();
    glm::vec2 spriteVelocity = spriteVelocityComponent->getVelocity();

    // only show animations if player is moving
    if (spriteVelocity.x == 0 && spriteVelocity.y == 0)
    {
        _srcRect.x = 0;
    }
    else
    {
        _srcRect.x = static_cast<int>((SDL_GetTicks() / _speed) % _numberOfFrames * _width);
    }

    // update rect dest position based on transform
    Vine::TransformComponent* transform = _owner->getComponent<Vine::TransformComponent>();
    const int x = transform->getPosition().x - Game::_camera.x;
    const int y = transform->getPosition().y;

    _destRect.x = x;
    _destRect.y = y;
}

void Vine::SpriteComponent::render()
{
    if (!_texture)
    {
        return;
    }

    SDL_RenderCopyEx(&_renderer, _texture, &_srcRect, &_destRect, 0, NULL, _flipped);
}
