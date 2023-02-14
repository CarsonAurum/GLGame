add_subdirectory(api)
add_subdirectory(app)
add_subdirectory(core)
add_subdirectory(debug)

set(TOA_SRCS ${TOA_SRCS} PARENT_SCOPE)
# message("Sources: ${TOA_SRCS}")