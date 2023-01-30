file(GLOB API_HEADERS
        api/*.hxx
        api/ecs/components/*.hxx
        api/ecs/core/*.hxx
        api/ecs/entites/*.hxx
        api/ecs/systems/*.hxx)
file(GLOB APP_HEADERS
        app/*.hxx)
file(GLOB DEBUG_HEADERS
        debug/*.hxx)

set(TOA_HEADERS ${API_HEADERS} ${APP_HEADERS} ${DEBUG_HEADERS} PARENT_SCOPE)
