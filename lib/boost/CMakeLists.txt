add_subdirectory(algorithm)
set(ALGORITHM_INC algorithm/include)
set(ALGORITHM_LIB boost_algorithm)

add_subdirectory(align)

add_subdirectory(array)

add_subdirectory(assert)

add_subdirectory(atomic)

add_subdirectory(bind)

add_subdirectory(chrono)

add_subdirectory(concept_check)

add_subdirectory(config)

add_subdirectory(container)
set(CONTAINER_INC container/include)
set(CONTAINER_SRC boost_container)

add_subdirectory(container_hash)

add_subdirectory(conversion)

add_subdirectory(core)

add_subdirectory(date_time)

add_subdirectory(detail)

add_subdirectory(describe)

add_subdirectory(dynamic_bitset)

add_subdirectory(endian)

add_subdirectory(exception)

add_subdirectory(function)

add_subdirectory(function_types)

add_subdirectory(functional)

add_subdirectory(fusion)

add_subdirectory(integer)

add_subdirectory(intrusive)

add_subdirectory(io)

add_subdirectory(iterator)

add_subdirectory(lexical_cast)

add_subdirectory(move)

add_subdirectory(mp11)

add_subdirectory(mpl)

add_subdirectory(numeric_conversion)

add_subdirectory(optional)

add_subdirectory(phoenix)

add_subdirectory(pool)

add_subdirectory(predef)

add_subdirectory(preprocessor)

add_subdirectory(proto)

add_subdirectory(random)

add_subdirectory(range)

add_subdirectory(ratio)

add_subdirectory(rational)

add_subdirectory(regex)

add_subdirectory(serialization)

add_subdirectory(smart_ptr)

add_subdirectory(sort)
set(SORT_INC sort/include)
set(SORT_LIB boost_sort)

add_subdirectory(spirit)

add_subdirectory(static_assert)

add_subdirectory(system)

add_subdirectory(thread)

add_subdirectory(throw_exception)

add_subdirectory(tokenizer)

add_subdirectory(tti)

add_subdirectory(tuple)
set(TUPLE_INC tuple/include)
set(TUPLE_SRC boost_tuple)

add_subdirectory(type_index)

add_subdirectory(type_traits)

add_subdirectory(typeof)

add_subdirectory(unordered)

add_subdirectory(utility)

add_subdirectory(uuid)
set(UUID_INC uuid/include)
set(UUID_LIB boost_uuid)

add_subdirectory(variant)

add_subdirectory(variant2)

add_subdirectory(winapi)

set(BOOST_INCLUDE_DIRS
        ${ALGORITHM_INC}
        ${CONTAINER_INC}
        ${SORT_INC}
        ${TUPLE_INC}
        ${UUID_INC}
    PARENT_SCOPE)
set(BOOST_LIBRARIES
        ${ALGORITHM_LIB}
        ${CONTAINER_LIB}
        ${SORT_LIB}
        ${TUPLE_LIB}
        ${UUID_LIB}
    PARENT_SCOPE)
