add_subdirectory(api)
add_subdirectory(app)
add_subdirectory(debug)

set(TOA_HEADERS ${TOA_HEADERS} PARENT_SCOPE)
# message("Headers: ${TOA_HEADERS}")