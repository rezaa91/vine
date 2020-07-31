#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "../BaseComponent.h"
#include <string>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>

namespace Vine {
    class SpriteComponent : public Vine::BaseComponent
    {
    private:
        SDL_Renderer& _renderer;
        SDL_Texture* _texture;
        glm::vec2 _position;
        const int _width;
        const int _height;
        const int _numberOfFrames;

        void loadTexture(const std::string filepath);
    public:
        SpriteComponent(
            SDL_Renderer& renderer,
            const std::string path,
            const int x,
            const int y,
            const int width,
            const int height,
            const int numberOfFrames = 1
        );

        void update(float deltaTime);
        void render();
    };
};

#endif