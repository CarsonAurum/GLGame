cmake_minimum_required(VERSION 3.24)
project(TitanOfAir)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)

add_executable(TitanOfAir main.cpp)

target_link_libraries(TitanOfAir PRIVATE ${GLAD_LIBRARIES} ${GLFW_LIBRARIES})
target_include_directories(TitanOfAir PRIVATE ${GLAD_INCLUDE_DIR} ${GLFW_INCLUDE_DIR})
