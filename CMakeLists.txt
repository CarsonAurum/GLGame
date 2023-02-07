cmake_minimum_required(VERSION 3.24)
project(TitanOfAir)

set(CMAKE_CXX_STANDARD 20)

# Project Sources + Headers
add_subdirectory(toa/inc)
add_subdirectory(toa/src)

# Declare Deliverable
add_executable(TitanOfAir ${TOA_HEADERS} ${TOA_SRCS})
target_include_directories(TitanOfAir PRIVATE toa/inc)

# Add Dependencies To Target
add_subdirectory(lib)
target_link_libraries(TitanOfAir PRIVATE ${GLAD_LIBRARIES} ${GLFW_LIBRARIES} ${SOIL_LIBRARIES})
target_link_libraries(TitanOfAir PRIVATE ${GLM_LIBRARIES} ${OPUS_LIBRARIES} ${SPDLOG_LIBRARIES})
target_link_libraries(TitanOfAir PRIVATE ${BOOST_LIBRARIES} ${BEHAVIOR_TREE_LIBRARIES} ${FLECS_LIBRARIES})
target_include_directories(TitanOfAir PRIVATE ${GLAD_INCLUDE_DIR} ${GLFW_INCLUDE_DIR} ${SOIL_INCLUDE_DIR})
target_include_directories(TitanOfAir PRIVATE ${GLM_INCLUDE_DIR} ${OPUS_INCLUDE_DIR} ${SPDLOG_INCLUDE_DIR})
target_include_directories(TitanOfAir PRIVATE ${BOOST_INCLUDE_DIRS} ${BEHAVIOR_TREE_INCLUDE_DIR} ${FLECS_INCLUDE_DIR})


if(WIN32)
target_link_libraries(TitanOfAir PRIVATE bcrypt)
endif()