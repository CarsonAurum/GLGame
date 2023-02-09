cmake_minimum_required(VERSION 3.24)

# Project Definition
set(PROJECT_NAME_STRING TitanOfAir)
project(${PROJECT_NAME_STRING})

# Project Options
option(BUILD_TESTS "Build the unit tests." ON)

# CMake Configuration
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# Project Sources + Headers
add_subdirectory(toa/inc)
add_subdirectory(toa/src)

# Libraries
add_subdirectory(lib)
find_package(Boost COMPONENTS filesystem REQUIRED)
if (BUILD_TESTS)
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
endif()
link_libraries(
        ${BEHAVIOR_TREE_LIBRARIES}
        ${Boost_LIBRARIES}
        ${FLECS_LIBRARIES}
        ${GLAD_LIBRARIES}
        ${GLFW_LIBRARIES}
        ${GLM_LIBRARIES}
        ${OPUS_LIBRARIES}
        ${SOIL_LIBRARIES}
        ${SPDLOG_LIBRARIES}
)
include_directories(
        ${BEHAVIOR_TREE_INCLUDE_DIR}
        ${Boost_INCLUDE_DIRS}
        ${FLECS_INCLUDE_DIR}
        ${GLAD_INCLUDE_DIR}
        ${GLFW_INCLUDE_DIR}
        ${GLM_INCLUDE_DIR}
        ${OPUS_INCLUDE_DIR}
        ${SOIL_INCLUDE_DIR}
        ${SPDLOG_INCLUDE_DIR}
)
if(WIN32)
    link_libraries(bcrypt)
endif()

# Declare Deliverable
add_executable(${PROJECT_NAME_STRING} ${TOA_HEADERS} ${TOA_SRCS})
target_include_directories(${PROJECT_NAME_STRING} PRIVATE toa/inc)

# Tests
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()