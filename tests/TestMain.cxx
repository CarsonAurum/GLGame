//
// Created by Carson Rau on 2/8/23.
//

#define BOOST_TEST_MODULE MainModule

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_main)
    BOOST_AUTO_TEST_CASE(first_test)
    {
        BOOST_TEST(true);
    }
    BOOST_AUTO_TEST_CASE(second_test)
    {
        BOOST_TEST(true);
    }
BOOST_AUTO_TEST_SUITE_END()