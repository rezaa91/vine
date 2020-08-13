#include "PlayerInput.h"
#include "../Config.h"
#include "../components/VelocityComponent.h"
#include "../components/SpriteComponent.h"
#include "../Entity.h"
#include <glm/glm.hpp>
#include <iostream>

Vine::PlayerInput::PlayerInput(Vine::Entity& player)
    : _player(player)
{}

void Vine::PlayerInput::onKeyUp()
{
    Vine::VelocityComponent& playerVelocityComponent = *_player.getComponent<Vine::VelocityComponent>();
    glm::vec2 playerVelocity = playerVelocityComponent.getVelocity();

    if (!_keyboardStates[Vine::Config::KeyboardBindings::SPRINT])
    {
        _sprintSpeed = 0;
    }

    if (!_keyboardStates[Vine::Config::KeyboardBindings::LEFT] &&
        !_keyboardStates[Vine::Config::KeyboardBindings::RIGHT])
    {
        playerVelocity.x = 0;
    }

    playerVelocityComponent.setVelocity(playerVelocity);
}

void Vine::PlayerInput::onKeyDown()
{
    Vine::VelocityComponent& playerVelocityComponent = *_player.getComponent<Vine::VelocityComponent>();
    glm::vec2 playerVelocity = playerVelocityComponent.getVelocity();

    Vine::SpriteComponent& playerSprite = *_player.getComponent<Vine::SpriteComponent>();

    if (_keyboardStates[Vine::Config::KeyboardBindings::SPRINT])
    {
        _sprintSpeed = 80;
    }

    if (_keyboardStates[Vine::Config::KeyboardBindings::LEFT])
    {
        playerVelocity.x = -80 - _sprintSpeed;
        playerSprite.setFlipped(true);
    }

    if (_keyboardStates[Vine::Config::KeyboardBindings::RIGHT])
    {
        playerVelocity.x = 80 + _sprintSpeed;
        playerSprite.setFlipped(false);
    }

    if (_keyboardStates[Vine::Config::KeyboardBindings::JUMP])
    {

    }

    playerVelocityComponent.setVelocity(playerVelocity);
}

void Vine::PlayerInput::onMouseDown(Vine::MOUSE_BUTTON button)
{
    if (button == Vine::MOUSE_BUTTON::LEFT)
    {
        std::cout << "Left button down" << std::endl;
    }

    if (button == Vine::MOUSE_BUTTON::RIGHT)
    {
        std::cout << "Right button down" << std::endl;
    }
}

void Vine::PlayerInput::onMouseUp(Vine::MOUSE_BUTTON button)
{
    if (button == Vine::MOUSE_BUTTON::LEFT)
    {
        std::cout << "Left button up" << std::endl;
    }

    if (button == Vine::MOUSE_BUTTON::RIGHT)
    {
        std::cout << "Right button up" << std::endl;
    }
}

void Vine::PlayerInput::setMousePosition()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    _mousePosition = {x, y};
}


void Vine::PlayerInput::handleInput(SDL_Event& event)
{
    setMousePosition();
    _keyboardStates = SDL_GetKeyboardState(NULL);

    if (event.type == SDL_KEYDOWN)
    {
        onKeyDown();
    }

    if (event.type == SDL_KEYUP)
    {
        onKeyUp();
    }

    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        onMouseDown(static_cast<Vine::MOUSE_BUTTON>(event.button.button));
    }

    if (event.type == SDL_MOUSEBUTTONUP)
    {
        onMouseUp(static_cast<Vine::MOUSE_BUTTON>(event.button.button));
    }
}

glm::vec2 Vine::PlayerInput::getMousePosition() const
{
    return _mousePosition;
}
