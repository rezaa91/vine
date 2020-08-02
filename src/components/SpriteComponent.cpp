#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "VelocityComponent.h"
#include "../Entity.h"
#include <SDL2_Image/SDL_image.h>
#include <spdlog/spdlog.h>

Vine::SpriteComponent::SpriteComponent(
    SDL_Renderer& renderer,
    const std::string filepath,
    const int x,
    const int y,
    const int width,
    const int height,
    const int numberOfFrames,
    const int speed
)
    : _renderer(renderer),
    _position{x, y},
    _width(width),
    _height(height),
    _numberOfFrames(numberOfFrames),
    _speed(speed)
{
    loadTexture(filepath);
}

void Vine::SpriteComponent::loadTexture(const std::string filepath)
{
    spdlog::info("loading surface at: {}", filepath);
    SDL_Surface* tmpSurface = IMG_Load(filepath.c_str());

    if (!tmpSurface)
    {
        spdlog::error("Unable to load texture. Reason: {}", SDL_GetError());

        return;
    }

    _texture = SDL_CreateTextureFromSurface(&_renderer, tmpSurface);

    SDL_FreeSurface(tmpSurface);

    spdlog::debug("texture successfully loaded: {}", filepath);
}

void Vine::SpriteComponent::update(float deltaTime)
{
    Vine::VelocityComponent* spriteVelocityComponent = _owner->getComponent<Vine::VelocityComponent>();
    glm::vec2 spriteVelocity = spriteVelocityComponent->getVelocity();

    // only show animations if player is moving
    if (spriteVelocity.x == 0 && spriteVelocity.y == 0)
    {
        _srcX = 0;
    }
    else
    {
        _srcX = static_cast<int>((SDL_GetTicks() / _speed) % _numberOfFrames * _width);
    }
}

void Vine::SpriteComponent::render()
{
    if (!_texture)
    {
        return;
    }

    Vine::TransformComponent* transform = _owner->getComponent<Vine::TransformComponent>();
    const int x = transform->getPosition().x;
    const int y = transform->getPosition().y;

    SDL_Rect src {_srcX, 0, _width, _height};
    SDL_Rect dest {x, y, _width, _height};

    SDL_RenderCopyEx(&_renderer, _texture, &src, &dest, 0, NULL, _flipped);
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
