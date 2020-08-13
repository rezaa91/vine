#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

namespace Vine {
    class Input
    {
    public:
        virtual void handleInput(SDL_Event& event) = 0;
    };
};

#endif
