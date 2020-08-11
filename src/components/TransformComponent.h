#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "../BaseComponent.h"
#include <glm/glm.hpp>

namespace Vine {
    class TransformComponent : public Vine::BaseComponent
    {
    private:
        glm::vec2 _position;
        glm::vec2 _prevPosition;
        float _gravity = 0;
    public:
        TransformComponent(int x, int y);

        void setGravity(float gravity);
        glm::vec2 getPosition() const;
        glm::vec2 getPreviousPosition() const;
        void setPosition(glm::vec2 position);
        void update(float deltaTime) override;
        void render() override;
    };
};

#endif
