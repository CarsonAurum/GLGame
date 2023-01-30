//
// Carson R - 1/10/2023
//

#ifndef TITANOFAIR_APP_HXX
#define TITANOFAIR_APP_HXX

#include "api/ecs/core/ECSystem.hxx"

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

        bool init();

        // Public Constants
        static constexpr const char *GAME_NAME = "Titan Of Air";
        static constexpr const char *APP_NAME = "titan_of_air";
        static constexpr const char *LOG = "TitanOfAir";

    protected:
        // Internal Usage Only
        App();

        ~App();
    };
}

#endif //TITANOFAIR_APP_HXX
