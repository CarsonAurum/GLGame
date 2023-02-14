add_subdirectory(behavior_tree)
set(BEHAVIOR_TREE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/behavior_tree/include)
set(BEHAVIOR_TREE_LIBRARIES behaviortree_cpp)

add_subdirectory(flecs)
set(FLECS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/flecs/include)
set(FLECS_LIBRARIES flecs)

add_subdirectory(glad)
set(GLAD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glad/include)
set(GLAD_LIBRARIES glad)

add_subdirectory(glfw)
set(GLFW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include)
set(GLFW_LIBRARIES glfw ${GLFW_LIBRARIES})

add_subdirectory(glm)
set(GLM_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glm)
set(GLM_LIBRARIES glm::glm)

add_subdirectory(opus)
set(OPUS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/opus/include)
set(OPUS_LIBRARIES opus)

add_subdirectory(soil2)
set(SOIL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/soil2/src)
set(SOIL_LIBRARIES soil2)

add_subdirectory(spdlog)
set(SPDLOG_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/spdlog/include)
set(SPDLOG_LIBRARIES spdlog)

set(LIB_INCS
        ${BEHAVIOR_TREE_INCLUDE_DIR}
        ${FLECS_INCLUDE_DIR}
        ${GLAD_INCLUDE_DIR}
        ${GLFW_INCLUDE_DIR}
        ${GLM_INCLUDE_DIR}
        ${OPUS_INCLUDE_DIR}
        ${SOIL_INCLUDE_DIR}
        ${SPDLOG_INCLUDE_DIR}
        PARENT_SCOPE
)
set(LIB_SRCS
        ${BEHAVIOR_TREE_LIBRARIES}
        ${FLECS_LIBRARIES}
        ${GLAD_LIBRARIES}
        ${GLFW_LIBRARIES}
        ${GLM_LIBRARIES}
        ${OPUS_LIBRARIES}
        ${SOIL_LIBRARIES}
        ${SPDLOG_LIBRARIES}
        PARENT_SCOPE
)