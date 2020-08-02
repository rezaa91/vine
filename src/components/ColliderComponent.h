#ifndef COLLIDER_COMPONENT_H
#define COLLIDER_COMPONENT_H

#include "../BaseComponent.h"

namespace Vine {
    class ColliderComponent : public Vine::BaseComponent
    {
    public:
        ColliderComponent() = default;

        void update(float deltaTime) override;
        void render() override;
    };
};

#endif
