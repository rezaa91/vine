#ifndef TILE_COMPONENT_H
#define TILE_COMPONENT_H

#include "../BaseComponent.h"
#include <glm/glm.hpp>
#include <SDL2/SDL.h>

namespace Vine {
    enum class TILE_TYPE { GRASS_LEFT, GRASS_CENTER, GRASS_RIGHT, BLOCK };

    class TileComponent : public Vine::BaseComponent
    {
    private:
        SDL_Renderer& _renderer;
        SDL_Texture* _tileTexture;
        glm::vec2 _position;
        const int _width;
        const int _height;

        SDL_Rect _srcRect;
        SDL_Rect _destRect;
    public:
        TileComponent(
            SDL_Renderer& renderer,
            const int type,
            const int x,
            const int y,
            const int width,
            const int height
        );

        glm::vec2 getPosition() const;
        SDL_Rect getRect() const;
        void update(float deltaTime) override;
        void render() override;
    };
};

#endif
