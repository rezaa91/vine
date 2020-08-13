#include "GameInput.h"
#include "../Config.h"

Vine::GameInput::GameInput(Vine::Game& game)
    : _game(game)
{}

void Vine::GameInput::onKeyUp(SDL_Scancode key)
{
    switch (key)
    {
        case Vine::Config::KeyboardBindings::PAUSE:
            _game.togglePause();
            break;
    }
}

void Vine::GameInput::onKeyDown(SDL_Scancode key)
{
    switch (key)
    {
        
    }
}

void Vine::GameInput::handleInput(SDL_Event& event)
{
    switch (event.type)
    {
        case SDL_QUIT:
            _game.endGame();
            break;
        case SDL_KEYUP:
            onKeyUp(event.key.keysym.scancode);
            break;
        case SDL_KEYDOWN:
            onKeyDown(event.key.keysym.scancode);
            break;
    }
}