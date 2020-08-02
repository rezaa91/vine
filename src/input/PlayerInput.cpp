#include "PlayerInput.h"
#include "../Config.h"
#include "../components/VelocityComponent.h"
#include "../components/SpriteComponent.h"
#include "../Entity.h"
#include <glm/glm.hpp>

Vine::PlayerInput::PlayerInput(Vine::Entity& player)
    : _player(player)
{}

void Vine::PlayerInput::onKeyUp(SDL_Keycode key)
{
    Vine::VelocityComponent& playerVelocityComponent = *_player.getComponent<Vine::VelocityComponent>();
    glm::vec2 playerVelocity = playerVelocityComponent.getVelocity();

    switch (key)
    {
        case Vine::Config::KeyboardBindings::LEFT:
        case Vine::Config::KeyboardBindings::RIGHT:
            playerVelocity.x = 0;
            break;
        case Vine::Config::KeyboardBindings::UP:
        case Vine::Config::KeyboardBindings::DOWN:
            playerVelocity.y = 0;
            break;
        case Vine::Config::KeyboardBindings::JUMP:
            break;
    }

    playerVelocityComponent.setVelocity(playerVelocity);
}

void Vine::PlayerInput::onKeyDown(SDL_Keycode key)
{
    Vine::VelocityComponent& playerVelocityComponent = *_player.getComponent<Vine::VelocityComponent>();
    glm::vec2 playerVelocity = playerVelocityComponent.getVelocity();

    Vine::SpriteComponent& playerSprite = *_player.getComponent<Vine::SpriteComponent>();

    switch (key)
    {
        case Vine::Config::KeyboardBindings::LEFT:
            playerVelocity.x = -80;
            playerSprite.setFlipped(true);
            break;
        case Vine::Config::KeyboardBindings::RIGHT:
            playerVelocity.x = 80;
            playerSprite.setFlipped(false);
            break;
        case Vine::Config::KeyboardBindings::UP:
            playerVelocity.y = -80;
            break;
        case Vine::Config::KeyboardBindings::DOWN:
            playerVelocity.y = 80;
            break;
        case Vine::Config::KeyboardBindings::JUMP:
            break;
    }

    playerVelocityComponent.setVelocity(playerVelocity);
}

void Vine::PlayerInput::handleInput(SDL_Event& event)
{
    switch (event.type)
    {
        case SDL_KEYUP:
            onKeyUp(event.key.keysym.sym);
            break;
        case SDL_KEYDOWN:
            onKeyDown(event.key.keysym.sym);
            break;
    }
}