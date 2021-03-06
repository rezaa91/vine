#include "VelocityComponent.h"
#include <glm/glm.hpp>

Vine::VelocityComponent::VelocityComponent(int x, int y)
    : _velocity(x, y)
{}

void Vine::VelocityComponent::setVelocity(glm::vec2 velocity)
{
    _velocity = velocity;
}

glm::vec2 Vine::VelocityComponent::getVelocity() const
{
    return _velocity;
}

void Vine::VelocityComponent::update(float deltaTime)
{
}

void Vine::VelocityComponent::render()
{
}

