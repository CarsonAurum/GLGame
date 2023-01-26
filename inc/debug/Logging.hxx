//
// Carson R - 1/23/2023
//

#ifndef TITANOFAIR_LOGGING_HXX
#define TITANOFAIR_LOGGING_HXX

namespace TitanOfAir::logging
{
    /**
     * An internal function to configure the logging system for this application.
     *
     * The name of the primary logger created in this process can be accessed via the `App::LOG`
     * constant:
     * ```cpp
     *      spdlog::get(App::LOG)->info("An info string.");
     * ```
     */
    void configureLoggers();
}

#endif //TITANOFAIR_LOGGING_HXX
