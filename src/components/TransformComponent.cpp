#include "TransformComponent.h"
#include "VelocityComponent.h"
#include "../Entity.h"

Vine::TransformComponent::TransformComponent(int x, int y)
    : _position(x, y)
{}

glm::vec2 Vine::TransformComponent::getPosition() const
{
    return _position;
}

void Vine::TransformComponent::setPosition(glm::vec2 position)
{
    _position = position;
}

void Vine::TransformComponent::update(float deltaTime)
{
    VelocityComponent* velocity = _owner->getComponent<VelocityComponent>();
    _position.x += velocity->getVelocity().x * deltaTime;
    _position.y += velocity->getVelocity().y * deltaTime;
}

void Vine::TransformComponent::render()
{

}
