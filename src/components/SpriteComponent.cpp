#include "SpriteComponent.h"
#include "TransformComponent.h"
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
    const int numberOfFrames
)
    : _renderer(renderer),
    _position{x, y},
    _width(width),
    _height(height),
    _numberOfFrames(numberOfFrames)
{
    loadTexture(filepath);
}

void Vine::SpriteComponent::loadTexture(const std::string filepath)
{
    spdlog::info("loading surface at: {}", filepath);
    SDL_Surface* tmpSurface = IMG_Load(filepath.c_str());

    if (!tmpSurface)
    {
        spdlog::warn("Unable to load texture at: {}", filepath);

        return;
    }

    _texture = SDL_CreateTextureFromSurface(&_renderer, tmpSurface);

    SDL_FreeSurface(tmpSurface);

    spdlog::debug("texture successfully loaded: {}", filepath);
}

void Vine::SpriteComponent::update(float deltaTime)
{
    
}

void Vine::SpriteComponent::render()
{
    Vine::TransformComponent* transform = _owner->getComponent<Vine::TransformComponent>();
    const int x = transform->getPosition().x;
    const int y = transform->getPosition().y;

    SDL_Rect src {0, 0, _width, _height};
    SDL_Rect dest {x, y, _width, _height};

    SDL_RenderCopy(&_renderer, _texture, &src, &dest);
}
