#ifndef BASE_COMPONENT_H
#define BASE_COMPONENT_H

namespace Vine {
    class Entity;

    class BaseComponent
    {
    protected:
        Vine::Entity* _owner;
    public:
        BaseComponent() = default;
        void setOwner(Vine::Entity* owner)
        {
            _owner = owner;
        }

        virtual void update(float deltaTime) = 0;
        virtual void render() = 0;
    };
};

#endif
