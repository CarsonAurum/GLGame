add_subdirectory(array)

add_subdirectory(assert)

add_subdirectory(concept_check)

add_subdirectory(config)

add_subdirectory(container)

add_subdirectory(container_hash)

add_subdirectory(conversion)

add_subdirectory(core)

add_subdirectory(describe)

add_subdirectory(dynamic_bitset)

add_subdirectory(exception)

add_subdirectory(integer)

add_subdirectory(intrusive)

add_subdirectory(io)

add_subdirectory(move)

add_subdirectory(mp11)

add_subdirectory(numeric_conversion)

add_subdirectory(predef)

add_subdirectory(preprocessor)

add_subdirectory(random)

add_subdirectory(range)

add_subdirectory(serialization)

add_subdirectory(smart_ptr)

add_subdirectory(static_assert)

add_subdirectory(system)

add_subdirectory(throw_exception)

add_subdirectory(tti)

add_subdirectory(tuple)

add_subdirectory(type_traits)

add_subdirectory(utility)

add_subdirectory(uuid)

add_subdirectory(winapi)

set(BOOST_INCLUDE_DIRS
        ${ASSERT_INC} ${CONFIG_INC} ${CONTAINER_INC} ${CORE_INC} ${INTRUSIVE_INC} ${IO_INC}
        ${MOVE_INC}
        PARENT_SCOPE)
set(BOOST_LIBRARIES
        ${ASSERT_LIB} ${CONFIG_LIB} ${CONTAINER_LIB} ${CORE_LIB} ${INTRUSIVE_LIB} ${IO_LIB}

        ${MOVE_LIB}
        PARENT_SCOPE)
