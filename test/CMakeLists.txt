cmake_minimum_required(VERSION 3.5)

# Project settings
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ".")
set(PROJECT_UNIT_TESTS ${PROJECT_NAME}_Test)

set(BOOST_TEST_INC ${CMAKE_SOURCE_DIR}/lib/boost/test/include)
set(BOOST_TEST_LIB boost_unit_test_framework)

# Gather the header and source files
file(GLOB UNIT_TESTS_INC ${PROJECT_SOURCE_DIR}/test/*.hxx)
file(GLOB UNIT_TESTS_SRC ${PROJECT_SOURCE_DIR}/test/*.cxx)

# Include paths
set(UNIT_TESTS_INCLUDES ${PROJECT_INCLUDE_DIR} ${PROJECT_SOURCE_DIR}/src ${BOOST_TEST_INC})

# Assign the include directories
include_directories(${BOOST_TEST_INC})
include_directories(${UNIT_TESTS_INCLUDES})

# Build unit tests
add_definitions(-DBOOST_TEST_DYN_LINK)
#add_executable(${PROJECT_UNIT_TESTS_NAME} ${UNIT_TESTS_SRC_FILES} $<TARGET_OBJECTS:demo_objects> )
add_executable(${PROJECT_UNIT_TESTS} ${UNIT_TESTS_SRC} ${SRC_FILES})
target_link_libraries(${PROJECT_UNIT_TESTS} ${BOOST_TEST_LIB})

enable_testing()
add_test(DemoTest ${PROJECT_UNIT_TESTS})