include(TestHelper)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ".")
set(TEST_PROJECT_NAME ${PROJECT_NAME_STRING}_Tests)

file(GLOB TEST_SRCS *.cxx)
file(GLOB TEST_INCS *.hxx)

add_definitions(-DBOOST_TEST_DYN_LINK)

add_executable(${TEST_PROJECT_NAME} ${TEST_SRCS} ${TEST_INCS})

target_include_directories(${TEST_PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/toa/inc
        ${CMAKE_SOURCE_DIR}/toa/src
        TEST_INCS
)

enable_testing()
add_boost_test(SOURCE TestMain.cxx)
