#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SDL2/SDL.h>

namespace Vine {
    class InputManager
    {
    public:
        InputManager() = default;
        void pollEvent(SDL_Event& event);
    };
};

#endif
