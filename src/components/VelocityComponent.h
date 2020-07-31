#ifndef VELOCITY_COMPONENT_H
#define VELOCITY_COMPONENT_H

#include "../BaseComponent.h"
#include <glm/glm.hpp>

namespace Vine {
    class VelocityComponent : public Vine::BaseComponent
    {
    private:
        glm::vec2 _velocity;
    public:
        VelocityComponent(int x, int y);

        glm::vec2 getVelocity() const;
        void update(float deltaTime);
        void render();
    };
};

#endif
