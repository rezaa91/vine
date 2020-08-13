#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "Entity.h"
#include <string>
#include <vector>

namespace Vine {
    class EntityManager
    {
    private:
        std::vector<Vine::Entity*> _entities;
    public:
        EntityManager() = default;
        ~EntityManager() = default;

        const std::vector<Vine::Entity*>& getEntities() const;
        bool hasEntities() const;
        void listEntities() const;
        Vine::Entity& addEntity(const std::string entityName);

        void update(float deltaTime);
        void render();
    };
};

#endif
