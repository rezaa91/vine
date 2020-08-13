#include "GameStates.h"
#include <iostream>

void Vine::GameState::push(Vine::State* state)
{
    if (_states.size() == 0)
    {
        _states.push(state);
        state->onEnter();

        return;
    }

    Vine::State* prevState = _states.top();
    _states.pop();
    _states.push(state);

    prevState->onExit();
    state->onEnter();
}


void Vine::MenuState::onEnter()
{
    std::cout << "Entering menu state" << std::endl;
}

void Vine::MenuState::onExit()
{
    std::cout << "Exiting menu state" << std::endl;
}


void Vine::PauseState::onEnter()
{
    std::cout << "Entering pause state" << std::endl;
}

void Vine::PauseState::onExit()
{
    std::cout << "Exiting pause state" << std::endl;
}


void Vine::PlayState::onEnter()
{
    std::cout << "Entering play state" << std::endl;
}

void Vine::PlayState::onExit()
{
    std::cout << "Exiting play state" << std::endl;
}
