#ifndef PLAYER_INPUT_H
#define PLAYER_INPUT_H

#include "Input.h"

namespace Vine {
    class Entity;

    class PlayerInput : public Vine::Input
    {
    private:
        Vine::Entity& _player;

        void onKeyUp(SDL_Keycode key) override;
        void onKeyDown(SDL_Keycode key) override;
    public:
        PlayerInput(Vine::Entity& player);
        void handleInput(SDL_Event& event) override;
    };
};

#endif
