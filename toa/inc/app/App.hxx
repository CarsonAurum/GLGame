//
// Carson R - 1/10/2023
//

#ifndef TITANOFAIR_APP_HXX
#define TITANOFAIR_APP_HXX

#include <flecs.h>

namespace TitanOfAir
{
    /**
     * @brief A class/namespace for central data to the application.
     */
    class App
    {
    public:
        // Singleton API
        /**
         * @brief The `App` class is explicitly non-copyable.
         */
        App(const App&) = delete;

        /**
         * @brief The `App` class is explicitly non-copyable.
         */
        App& operator =(const App&) = delete;

        /**
         * @brief The `App` class is explicitly immovable.
         */
        App(App&&) = delete;

        /**
         * @brief The `App` class is explicitly immovable.
         */
        App& operator =(App&&) = delete;

        /**
         * Access the singleton instance of this class.
         * @note NO move/copy allowed.
         * @return This class' global instance.
         */
        static App* shared();

        /**
         * Initialize this application's internal mechanisms once the game context has been loaded.
         * @return `true` if initialization was successful, `false` otherwise.
         */
        bool init();

        // Public Constants
        /**
         * @brief The *Pretty String* version of the game name.
         */
        static constexpr const char* GAME_NAME = "Titan Of Air";
        /**
         * @brief The *snake_case version of the game name.*
         */
        static constexpr const char* APP_NAME = "titan_of_air";
        /**
         * @brief The *PascalCase* version of the game name.
         * @details This version of the game name can be used to access the global logger via:
         * ```cpp
         * spdlog::get(App::LOG)->info("Info Message.");
         * ```
         */
        static constexpr const char* LOG = "TitanOfAir";
    private:
        flecs::world airports;
        flecs::world airplanes;
        flecs::world company;
        flecs::world travellers;

        App();

        ~App();
    };
}

#endif //TITANOFAIR_APP_HXX
