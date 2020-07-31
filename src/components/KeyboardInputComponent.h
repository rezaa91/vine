#ifndef KEYBOARD_INPUT_COMPONENT_H
#define KEYBOARD_INPUT_COMPONENT_H

#include "../BaseComponent.h"

namespace Vine {
    class KeyboardInputComponent : public Vine::BaseComponent
    {
    public:
        KeyboardInputComponent() = default;

        void update(float deltaTime);
        void render();
    };
};

#endif
