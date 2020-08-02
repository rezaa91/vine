#ifndef TILE_COMPONENT_H
#define TILE_COMPONENT_H

#include "../BaseComponent.h"

namespace Vine {
    class TileComponent : public Vine::BaseComponent
    {
    public:
        TileComponent() = default;

        void update(float deltaTime) override;
        void render() override;
    };
};

#endif
