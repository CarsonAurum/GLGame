//
// Carson R - 1/10/2023
//

#ifndef TITANOFAIR_APP_HXX
#define TITANOFAIR_APP_HXX

#include "api/ecs/entities/Entity.hxx"
// NOTE: These will become less efficient with more items.
// Keep an eye on object counts for these containers.
#include <boost/tuple/tuple.hpp>
#include <boost/container/flat_set.hpp>
#include <boost/container/flat_map.hpp>
#include <boost/thread/shared_mutex.hpp>
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
        // Types
        /**
         * The ActionResult is a 4 digit code representing a more detailed response from
         * functions within this class.
         *
         * Code List:
         * [00xx]           =   General App Codes
         *      [0000]          =   APP_SUCCESS
         *      [0001]          =   APP_FAILURE
         * [01xx]           =   Entity Codes
         *      [0100]          =   APP_ENTY_OP_SUCCESS
         *      [0101]          =   APP_ENTY_OP_ERROR
         *      [0102]          =   APP_ENTY_PRESENT
         *      [0103]          =   APP_ENTY_NOT_PRESENT
         * [02xx]           =   Component Codes
         *      [0200]          =   APP_CMPT_OP_SUCCESS
         *      [0201]          =   APP_CMPT_OP_ERROR
         *      [0202]          =   APP_CMPT_PRESENT
         *      [0203]          =   APP_CMPT_NOT_PRESENT
         *
         * @see `inc/api/Except.hxx`
         */
        enum ActionResult
        {
            // [App General Codes 00xx]
            APP_SUCCESS = 0000,
            APP_FAILURE = 0001,


            // [Entity Codes 01xx]
            APP_ENTY_OP_SUCCESS = 0100,
            APP_ENTY_OP_ERROR = 0101,
            APP_ENTY_PRESENT = 0102,
            APP_ENTY_NOT_PRESENT = 0103,

            // [Component Codes 02xx]
            APP_CMPT_OP_SUCCESS = 0200,
            APP_CMPT_OP_ERROR = 0201,
            APP_CMPT_PRESENT = 0202,
            APP_CMPT_NOT_PRESENT = 0203,
        };

        // Singleton API
        App(App &) = delete;

        void operator=(const App &) = delete;

        /**
         * Access the singleton instance of this class. NO move/copy allowed.
         * @return This class' global instance.
         */
        static App *shared();

        void init();

        // Public Constants
        static constexpr const char *GAME_NAME = "Titan Of Air";
        static constexpr const char *APP_NAME = "titan_of_air";
        static constexpr const char *LOG = "TitanOfAir";

        // ECS
        std::size_t eCount();

        std::size_t cCount();

        ActionResult add(Entity *);

        ActionResult remove(Entity *);

        ActionResult getStatusFor(Entity *);

        ActionResult add(Component *);

        ActionResult remove(Component *);

        ActionResult getStatusFor(Component *);

    protected:
        // Internal Usage Only
        App();

        ~App();

        bool hasEntity(Entity *);

        bool hasComponent(Component *);

        bool clearECS();

    private:
        // ECS
        boost::shared_mutex *eMutex;
        boost::container::flat_set<const boost::uuids::uuid *> *entities;
        boost::shared_mutex *cMutex;
        boost::container::flat_set<const boost::uuids::uuid *> *components;
        boost::shared_mutex *esMutex;
        boost::container::flat_map<const boost::uuids::uuid *, ActionResult> *eStatus;
        boost::shared_mutex *csMutex;
        boost::container::flat_map<const boost::uuids::uuid *, ActionResult> *cStatus;
    };
}

#endif //TITANOFAIR_APP_HXX
