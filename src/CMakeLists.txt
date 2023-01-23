file(GLOB APP_SRCS app/*.cxx)
file(GLOB CORE_SRCS core/*.cxx)
file(GLOB DEBUG_SRCS debug/*.cxx)
set(TOA_SRCS ${APP_SRCS} ${CORE_SRCS} ${DEBUG_SRCS} PARENT_SCOPE)