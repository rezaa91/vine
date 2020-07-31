#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <SDL2/SDL.h>

namespace Vine {
    namespace Config {
        namespace Game {
            const std::string WINDOW_TITLE = "VINE 2D ENGINE";
            const int WIDTH = 1280;
            const int HEIGHT = 720;
            const int FPS = 60;
            const int FRAME_TARGET_TIME = 1000 / FPS;
        }

        namespace KeyboardBindings {
            const SDL_Keycode PAUSE = SDLK_ESCAPE;
            const SDL_Keycode LEFT = SDLK_a;
            const SDL_Keycode UP = SDLK_w;
            const SDL_Keycode RIGHT = SDLK_d;
            const SDL_Keycode DOWN = SDLK_s;
            const SDL_Keycode JUMP = SDLK_SPACE;
        }
    }
}

#endif
