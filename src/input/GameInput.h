#ifndef GAME_INPUT_H
#define GAME_INPUT_H

#include "Input.h"
#include "Game.h"

namespace Vine {
    class GameInput : public Vine::Input
    {
    private:
        Vine::Game& _game;

        void onKeyUp(SDL_Scancode key);
        void onKeyDown(SDL_Scancode key);
    public:
        GameInput(Vine::Game& game);
        void handleInput(SDL_Event& event) override;
    };
};

#endif
