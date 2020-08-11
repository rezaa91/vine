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

void Vine::TransformComponent::setGravity(float gravity)
{
    _gravity = gravity;
}

glm::vec2 Vine::TransformComponent::getPreviousPosition() const
{
    return _prevPosition;
}

void Vine::TransformComponent::setPosition(glm::vec2 position)
{
    _position = position;
}

void Vine::TransformComponent::update(float deltaTime)
{
    _prevPosition = _position;

    VelocityComponent* velocity = _owner->getComponent<VelocityComponent>();
    _position.x += velocity->getVelocity().x * deltaTime;
    _position.y += velocity->getVelocity().y * deltaTime; //+ _gravity;
}

void Vine::TransformComponent::render()
{

}
