#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "../BaseComponent.h"
#include <glm/glm.hpp>

namespace Vine {
    class TransformComponent : public Vine::BaseComponent
    {
    private:
        glm::vec2 _position;
    public:
        TransformComponent(int x, int y);

        glm::vec2 getPosition() const;
        void setPosition(glm::vec2 position);
        void update(float deltaTime) override;
        void render() override;
    };
};

#endif
