#ifndef MAP_H
#define MAP_H

#include "components/TileComponent.h"
#include <vector>
#include <string>
#include <SDL2/SDL.h>

namespace Vine {
    class Map
    {
    private:
        SDL_Renderer& _renderer;
        const std::string _mapFile;
        const int _tileSize;
        const int _width;
        const int _height;

    public:
        Map(
            SDL_Renderer& renderer,
            const std::string mapFile,
            const int tileSize,
            const int width,
            const int height
        );
        std::vector<Vine::TileComponent*> createTiles();
    };
};

#endif
