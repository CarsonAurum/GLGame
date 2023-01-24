add_subdirectory(assert)
set(ASSERT_INC assert/include)
set(ASSERT_LIB boost_assert)

add_subdirectory(config)
set(CONFIG_INC config/include)
set(CONFIG_LIB boost_config)

add_subdirectory(container)
set(CONTAINER_INC container/include)
set(CONTAINER_LIB boost_container)

add_subdirectory(container_hash)
set(CONTAINERHASH_INC container_hash/include)
set(CONTAINERHASH_LIB boost_container_hash)

add_subdirectory(core)
set(CORE_INC core/include)
set(CORE_LIB boost_core)

add_subdirectory(exception)
set(EXCEPTION_INC exception/include)
set(EXCEPTION_LIB boost_exception)

add_subdirectory(intrusive)
set(INTRUSIVE_INC intrusive/include)
set(INTRUSIVE_LIB boost_intrusive)

add_subdirectory(io)
set(IO_INC io/include)
set(IO_LIB boost_io)

add_subdirectory(move)
set(MOVE_INC move/include)
set(MOVE_LIB boost_move)

set(BOOST_INCLUDE_DIRS
        ${ASSERT_INC} ${CONFIG_INC} ${CONTAINER_INC} ${CORE_INC} ${INTRUSIVE_INC} ${IO_INC}
        ${MOVE_INC}
        PARENT_SCOPE)
set(BOOST_LIBRARIES
        ${ASSERT_LIB} ${CONFIG_LIB} ${CONTAINER_LIB} ${CORE_LIB} ${INTRUSIVE_LIB} ${IO_LIB}
        ${MOVE_LIB}
        PARENT_SCOPE)
