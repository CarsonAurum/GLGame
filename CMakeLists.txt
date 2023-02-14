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

# Libraries
add_subdirectory(lib)
find_package(Boost COMPONENTS filesystem REQUIRED)
if (BUILD_TESTS)
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
    enable_testing()
endif()
link_libraries(${LIB_SRCS} ${Boost_LIBRARIES})
include_directories(${LIB_INCS} ${Boost_INCLUDE_DIRS})
if(WIN32)
    link_libraries(bcrypt)
endif()

# Project Sources + Headers
add_subdirectory(toa/inc)
add_subdirectory(toa/src)

# Declare Deliverable
add_executable(${PROJECT_NAME_STRING} ${TOA_HEADERS} ${TOA_SRCS})
target_include_directories(${PROJECT_NAME_STRING} PRIVATE toa/inc)

# Tests
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()