#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "../BaseComponent.h"
#include <string>
#include <SDL2/SDL.h>

namespace Vine {
    class SpriteComponent : public Vine::BaseComponent
    {
    private:
        SDL_Renderer& _renderer;
        SDL_Texture* _texture;
        int _srcX;
        int _srcY;
        const int _width;
        const int _height;
        const int _numberOfFrames;
        const int _speed;
        SDL_RendererFlip _flipped = SDL_FLIP_NONE;
        SDL_Rect _srcRect;
        SDL_Rect _destRect;
    public:
        SpriteComponent(
            SDL_Renderer& renderer,
            const std::string textureName,
            const int x,
            const int y,
            const int width,
            const int height,
            const int numberOfFrames = 1,
            const int speed = 100
        );
        void setFlipped(bool flip);
        SDL_Rect getRect() const;

        void update(float deltaTime) override;
        void render() override;
    };
};

#endif