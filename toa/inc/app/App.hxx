//
// Carson R - 1/10/2023
//

#ifndef TITANOFAIR_APP_HXX
#define TITANOFAIR_APP_HXX

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
        /**
         * The `App` class is explicitly non-copyable.
         */
        App(const App &) = delete;
        /**
         * The `App` class is explicitly non-copyable.
         */
        App& operator=(const App &) = delete;
        /**
         * The `App` class is explicitly immovable.
         */
        App(App&&) = delete;
        /**
         * The `App` class is explicitly immovable.
         */
        App& operator=(App&&) = delete;

        /**
         * Access the singleton instance of this class. NO move/copy allowed.
         * @return This class' global instance.
         */
        static App *shared();

        /**
         * Initialize this application's internal mechanisms once the game context has been loaded.
         * @return `true` if initialization was successful, `false` otherwise.
         */
        bool init();

        // Public Constants
        static constexpr const char *GAME_NAME = "Titan Of Air";
        static constexpr const char *APP_NAME = "titan_of_air";
        static constexpr const char *LOG = "TitanOfAir";
    private:
        // Internal Usage Only
        App();
        ~App();
    };
}

#endif //TITANOFAIR_APP_HXX
