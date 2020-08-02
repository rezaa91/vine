#ifndef GAME_INPUT_H
#define GAME_INPUT_H

#include "Input.h"
#include "Game.h"

namespace Vine {
    class GameInput : public Vine::Input
    {
    private:
        Vine::Game& _game;

        void onKeyUp(SDL_Keycode key) override;
        void onKeyDown(SDL_Keycode key) override;
    public:
        GameInput(Vine::Game& game);
        void handleInput(SDL_Event& event) override;
    };
};

#endif
