#include "Entity.h"

Vine::Entity::Entity(const std::string name)
    : _name(name)
{}

const std::string& Vine::Entity::getName() const
{
    return _name;
}


void Vine::Entity::update(float deltaTime)
{
    if (!hasComponents())
    {
        return;
    }

    for (auto& component : _components)
    {
        component->update(deltaTime);
    }
}

void Vine::Entity::render()
{
    if (!hasComponents())
    {
        return;
    }

    for (auto& component : _components)
    {
        component->render();
    }
}

bool Vine::Entity::hasComponents() const
{
    return _components.size() > 0;
}
