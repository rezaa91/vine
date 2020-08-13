#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <SDL2/SDL.h>

namespace Vine {
    namespace Config {
        namespace Game {
            const std::string WINDOW_TITLE = "VINE 2D ENGINE";
            const int WIDTH = 1280;
            const int HEIGHT = 800;
            const int FPS = 60;
            const int FRAME_TARGET_TIME = 1000 / FPS;
        }

        namespace Map {
            const int TILE_SIZE = 32;
            const int WIDTH = 100;
            const int HEIGHT = 50;
        }

        namespace Player {
            // floor starts 2 levels up. - size of player sprite (32px)
            const int GROUND_LEVEL = Vine::Config::Game::HEIGHT - (2* Vine::Config::Map::TILE_SIZE) - 32;
        }

        namespace KeyboardBindings {
            const SDL_Scancode PAUSE = SDL_SCANCODE_ESCAPE;
            const SDL_Scancode LEFT = SDL_SCANCODE_A;
            const SDL_Scancode UP = SDL_SCANCODE_W;
            const SDL_Scancode RIGHT = SDL_SCANCODE_D;
            const SDL_Scancode DOWN = SDL_SCANCODE_S;
            const SDL_Scancode JUMP = SDL_SCANCODE_SPACE;
            const SDL_Scancode SPRINT = SDL_SCANCODE_LSHIFT;
        }
    }
}

#endif
