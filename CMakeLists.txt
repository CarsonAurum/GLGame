cmake_minimum_required(VERSION 3.24)
project(TitanOfAir)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)
add_subdirectory(inc)
add_subdirectory(src)

add_executable(TitanOfAir ${TOA_HEADERS} ${TOA_SRCS})

target_link_libraries(TitanOfAir PRIVATE ${GLAD_LIBRARIES} ${GLFW_LIBRARIES} ${SOIL_LIBRARIES})
target_link_libraries(TitanOfAir PRIVATE ${GLM_LIBRARIES} ${OPUS_LIBRARIES} ${SPDLOG_LIBRARIES})

target_include_directories(TitanOfAir PRIVATE ${GLAD_INCLUDE_DIR} ${GLFW_INCLUDE_DIR} ${SOIL_INCLUDE_DIR})
target_include_directories(TitanOfAir PRIVATE ${GLM_INCLUDE_DIR} ${OPUS_INCLUDE_DIR} ${SPDLOG_INCLUDE_DIR})
