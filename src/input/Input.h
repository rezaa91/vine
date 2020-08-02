#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

namespace Vine {
    class Input
    {
    private:
        virtual void onKeyUp(SDL_Keycode key) = 0;
        virtual void onKeyDown(SDL_Keycode key) = 0;
        // mouse events needed too
    public:
        virtual void handleInput(SDL_Event& event) = 0;
    };
};

#endif
