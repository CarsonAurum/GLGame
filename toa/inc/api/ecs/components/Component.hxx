//
// Carson R - 1/23/23
//

#ifndef TITANOFAIR_COMPONENT_HXX
#define TITANOFAIR_COMPONENT_HXX

// Libs
#include "api/ecs/core/ECS.hxx"

namespace TitanOfAir::ECS
{
    class Component
    {
    public:
        Component();

        Component(const Component& copy) = delete;

        Component& operator=(const Component& lhs) = delete;

        Component(Component&& move);

        Component operator=(Component&& lhs);

        ~Component();

        [[nodiscard]] std::string getID();

    protected:
        ECData* data;
    private:
        friend ECSystem;
    };
}

#endif //TITANOFAIR_COMPONENT_HXX
