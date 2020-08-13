#include "Map.h"
#include <spdlog/spdlog.h>
#include <fstream>

Vine::Map::Map(
    SDL_Renderer& renderer,
    const std::string mapFile,
    const int tileSize,
    const int width,
    const int height
    )
    : _renderer(renderer),
    _mapFile(mapFile),
    _tileSize(tileSize),
    _width(width),
    _height(height)
{}

std::vector<Vine::TileComponent*> Vine::Map::createTiles()
{
    std::vector<Vine::TileComponent*> tiles;

    spdlog::info("Opening map from: {}", _mapFile);
    std::fstream map;
    map.open(_mapFile);
    char c;

    for (int y = 0; y < _height; y++)
    {
        for (int x = 0; x < _width; x++)
        {
            map.get(c);
            int tileType = c - '0';

            switch (static_cast<Vine::TILE_TYPE>(tileType))
            {
                case Vine::TILE_TYPE::BLOCK:
                case Vine::TILE_TYPE::GRASS_CENTER:
                case Vine::TILE_TYPE::GRASS_LEFT:
                case Vine::TILE_TYPE::GRASS_RIGHT:
                    tiles.emplace_back(new Vine::TileComponent{*&_renderer, tileType, x * _tileSize, y * _tileSize, _tileSize, _tileSize});
                    break;
            }

            // ignore comma
            map.ignore();
        }
    }

    map.close();

    return tiles;
}
