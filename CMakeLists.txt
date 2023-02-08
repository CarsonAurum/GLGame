cmake_minimum_required(VERSION 3.24)

set(PROJECT_NAME_STRING TitanOfAir)
project(${PROJECT_NAME_STRING})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Project Sources + Headers
add_subdirectory(toa/inc)
add_subdirectory(toa/src)

# Declare Deliverable
add_executable(${PROJECT_NAME_STRING} ${TOA_HEADERS} ${TOA_SRCS})
target_include_directories(${PROJECT_NAME_STRING} PRIVATE toa/inc)

# Add Dependencies To Target
add_subdirectory(lib)
# TODO: Add Boost dependencies via find_package()
# TODO: Make README note about boost requirements.
target_link_libraries(${PROJECT_NAME_STRING} PRIVATE ${GLAD_LIBRARIES} ${GLFW_LIBRARIES} ${SOIL_LIBRARIES})
target_link_libraries(${PROJECT_NAME_STRING} PRIVATE ${GLM_LIBRARIES} ${OPUS_LIBRARIES} ${SPDLOG_LIBRARIES})
target_link_libraries(${PROJECT_NAME_STRING} PRIVATE ${BEHAVIOR_TREE_LIBRARIES} ${FLECS_LIBRARIES})
target_include_directories(${PROJECT_NAME_STRING} PRIVATE ${GLAD_INCLUDE_DIR} ${GLFW_INCLUDE_DIR} ${SOIL_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME_STRING} PRIVATE ${GLM_INCLUDE_DIR} ${OPUS_INCLUDE_DIR} ${SPDLOG_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME_STRING} PRIVATE ${BEHAVIOR_TREE_INCLUDE_DIR} ${FLECS_INCLUDE_DIR})

if(WIN32)
target_link_libraries(${PROJECT_NAME_STRING} PRIVATE bcrypt)
endif()