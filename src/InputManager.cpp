#include "InputManager.h"
#include <iostream>

void Vine::InputManager::pollEvent(SDL_Event& event)
{
    switch (event.type)
    {
        case SDL_KEYDOWN:
            std::cout << "KEY DOWN" << std::endl;
            break;
        case SDL_KEYUP:
            std::cout << "KEY UP" << std::endl;
            break;
    }
}
