#include "EntityManager.h"
#include <iostream>

const std::vector<Vine::Entity*>& Vine::EntityManager::getEntities() const
{
    return _entities;
}

bool Vine::EntityManager::hasEntities() const
{
    return _entities.size() > 0;
}

void Vine::EntityManager::listEntities() const
{
    for (auto& entity : _entities)
    {
        std::cout << entity->getName() << std::endl;
    }
}

Vine::Entity& Vine::EntityManager::addEntity(const std::string entityName)
{
    Vine::Entity* entity = new Vine::Entity(entityName);
    _entities.emplace_back(entity);

    return *entity;
}

void Vine::EntityManager::update(float deltaTime)
{
    for (auto& entity : _entities)
    {
        entity->update(deltaTime);
    }
}

void Vine::EntityManager::render()
{
    for (auto& entity : _entities)
    {
        entity->render();
    }
}
