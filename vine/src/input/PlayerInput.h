#ifndef PLAYER_INPUT_H
#define PLAYER_INPUT_H

#include "Input.h"
#include <glm/glm.hpp>

namespace Vine {
    class Entity;

    enum class MOUSE_BUTTON { LEFT, MIDDLE, RIGHT };

    class PlayerInput : public Vine::Input
    {
    private:
        Vine::Entity& _player;
        glm::vec2 _mousePosition;
        int _sprintSpeed = 0;
        const Uint8* _keyboardStates;

        void onKeyUp();
        void onKeyDown();
        void onMouseDown(Vine::MOUSE_BUTTON button);
        void onMouseUp(Vine::MOUSE_BUTTON button);
        void setMousePosition();
    public:
        PlayerInput(Vine::Entity& player);
        void handleInput(SDL_Event& event) override;
        glm::vec2 getMousePosition() const;
    };
};

#endif
