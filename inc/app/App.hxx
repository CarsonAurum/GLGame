//
// Carson R - 1/10/2023
//

#ifndef TITANOFAIR_APP_HXX
#define TITANOFAIR_APP_HXX

#include "api/ecs/entities/Entity.hxx"
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
        // Types
        class Response : public std::exception
        {
        public:
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
                APP_ENTY_OK = 0104,

                // [Component Codes 02xx]
                APP_CMPT_OP_SUCCESS = 0200,
                APP_CMPT_OP_ERROR = 0201,
                APP_CMPT_PRESENT = 0202,
                APP_CMPT_NOT_PRESENT = 0203,
            };

            Response();
            Response(ActionResult);

            virtual const char *what() const noexcept;

            unsigned short getCode();

            bool is(ActionResult);

        private:
            ActionResult cause;
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

        Response add(Entity *);

        Response remove(Entity *);

        Response getStatusFor(Entity *);

        Response add(Component *);

        Response remove(Component *);

        Response getStatusFor(Component *);

    protected:
        // Internal Usage Only
        App();

        ~App();

        bool hasEntity(Entity *);

        bool hasComponent(Component *);

        bool clearECS();

        typedef const boost::uuids::uuid EcsID;
        typedef boost::tuples::tuple<const Entity*, Response*> EntityTuple;
        typedef std::pair<EcsID*, EntityTuple> EntityPair;
        typedef boost::unordered::unordered_map<EcsID *, EntityTuple> EntityContainer;
        typedef boost::tuples::tuple<const Component*, Response*> ComponentTuple;
        typedef std::pair<EcsID*, ComponentTuple> ComponentPair;
        typedef boost::unordered::unordered_map<EcsID *, ComponentTuple> ComponentContainer;

    private:
        // ECS
        boost::shared_mutex *eMutex;
        EntityContainer *entities;
        boost::shared_mutex *cMutex;
        ComponentContainer *components;
    };
}

#endif //TITANOFAIR_APP_HXX
