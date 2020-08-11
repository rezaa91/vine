#include "CollisionManager.h"
#include "components/SpriteComponent.h"
#include "Entity.h"

bool Vine::CollisionManager::isCollision(SDL_Rect& a, SDL_Rect& b)
{
    if (
        a.x + a.w > b.x &&
        a.x < b.x + b.w &&
        a.y + a.h > b.y &&
        a.y < b.y + b.h
    ) {
        return true;
    }

    return false;
}

bool Vine::CollisionManager::playerAndTilesCollision(Vine::Entity& player, std::vector<TileComponent*>& tiles)
{
    Vine::SpriteComponent* playerSprite = player.getComponent<Vine::SpriteComponent>();
    SDL_Rect playerRect = playerSprite->getRect();

    for (auto& tile : tiles)
    {
        if (isCollision(tile->getRect(), playerRect))
        {
            return true;
        }
    }

    return false;
}

