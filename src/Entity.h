#ifndef BASE_ENTITY_H
#define ENTITY_H

#include "BaseComponent.h"
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <typeinfo>

namespace Vine {
    class Entity
    {
    private:
        std::vector<Vine::BaseComponent*> _components;
        std::map<const std::type_info*, Vine::BaseComponent*> _mapComponentsToType;
        const std::string _name;

        friend Vine::BaseComponent;
    public:
        Entity(const std::string name);
        ~Entity() = default;

        const std::string& getName() const;
        void update(float deltaTime);
        void render();

        template<typename T, typename ...TArgs>
        void addComponent(TArgs&&... args)
        {
            T* component = (new T(std::forward<TArgs>(args)...));
            component->setOwner(this);
            _components.emplace_back(component);
            _mapComponentsToType[&typeid(*component)] = component;
        }

        template<typename T>
        T* getComponent()
        {
            return static_cast<T*>(_mapComponentsToType.at(&typeid(T)));
        }

        bool hasComponents() const;
    };
};

#endif
