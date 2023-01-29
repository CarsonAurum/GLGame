//
// Carson R - 1/10/2023
//

#ifndef TITANOFAIR_APP_HXX
#define TITANOFAIR_APP_HXX

#include "api/ecs/ECS.hxx"
// NOTE: These will become less efficient with more items.
// Keep an eye on object counts for these containers.
#include <boost/tuple/tuple.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/unordered/unordered_map.hpp>
#include <boost/uuid/uuid.hpp>

namespace TitanOfAir
{
    /**
     * A class/namespace for central data to the application.
     *
     * This class serves as the director for the built-in ECS system.
     */
    class App
    {
    public:
        // Singleton API
        App(App &) = delete;

        void operator=(const App &) = delete;

        /**
         * Access the singleton instance of this class. NO move/copy allowed.
         * @return This class' global instance.
         */
        static App *shared();

        Response init();

        // Public Constants
        static constexpr const char *GAME_NAME = "Titan Of Air";
        static constexpr const char *APP_NAME = "titan_of_air";
        static constexpr const char *LOG = "TitanOfAir";

        // ECS
        std::size_t eCount();

        std::size_t cCount();

        Response add(Entity *);

        Response remove(Entity *);

        const Response* getStatusFor(Entity *) const;

        Response add(Component *);

        Response remove(Component *);

        const Response* getStatusFor(Component *) const;

    protected:
        // Internal Usage Only
        App();

        ~App();

        bool has(Entity *) const;

        bool has(Component *) const;

        size_t clearECS();

    private:
        // ECS
        boost::shared_mutex* eMutex;
        EntityContainer* entities;
        boost::shared_mutex* cMutex;
        ComponentContainer* components;
    };
}

#endif //TITANOFAIR_APP_HXX
