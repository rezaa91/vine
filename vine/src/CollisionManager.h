#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "components/TileComponent.h"
#include <vector>
#include <SDL2/SDL.h>

namespace Vine {
    class Entity;

    class CollisionManager
    {
    private:
        bool isCollision(SDL_Rect& a, SDL_Rect& b);
    public:
        bool playerAndTilesCollision(Vine::Entity& player, std::vector<TileComponent*>& tiles);
    };
};

#endif
