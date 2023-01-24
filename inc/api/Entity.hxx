//
// Carson R - 1/17/2023
//

#ifndef TITANOFAIR_ENTITY_HXX
#define TITANOFAIR_ENTITY_HXX

#include <uuid_v4.h>
#include <endianness.h>

namespace TitanOfAir
{
    class Entity
    {
    public:
        Entity();
        Entity(const Entity& copy);
        Entity(Entity&& move);
        virtual ~Entity() = delete;
    private:
        UUIDv4::UUID id;
    };
}

#endif //TITANOFAIR_ENTITY_HXX
