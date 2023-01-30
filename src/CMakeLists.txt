file(GLOB API_SRCS
        api/*.cxx
        api/ecs/*.cxx
        api/ecs/components/*.cxx
        api/ecs/entities/*.cxx)
file(GLOB APP_SRCS app/*.cxx)
file(GLOB CORE_SRCS core/*.cxx)
file(GLOB DEBUG_SRCS debug/*.cxx)
set(TOA_SRCS ${API_SRCS} ${APP_SRCS} ${CORE_SRCS} ${DEBUG_SRCS} PARENT_SCOPE)