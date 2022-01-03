#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest

#include "classe_de_test.h"
#include <boost/test/unit_test.hpp>

/**
 * mkdir build && cd build
 * cmake ..
 * ./tests --report_level=detailed
 *
 *
 */

BOOST_AUTO_TEST_SUITE(suite1)

BOOST_AUTO_TEST_CASE(Case1)
{
  BOOST_TEST_CHECKPOINT("create float");
  float x = 9.5f;
  BOOST_CHECK(x != 0.0f);
  BOOST_CHECK_EQUAL(2,2); // for objects
  BOOST_TEST_MESSAGE("case 1 string"); // Write in log
}

BOOST_AUTO_TEST_CASE(Case2)
{
  float x = 9.5f;
  BOOST_CHECK(x != 0.0f);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(suite2)

BOOST_AUTO_TEST_CASE(Case3)
{
  float x = 9.5f;
  BOOST_CHECK(x != 0.0f);
}

BOOST_AUTO_TEST_CASE(Case4)
{
  float x = 9.5f;
  BOOST_CHECK(x != 0.0f);
}

BOOST_AUTO_TEST_SUITE_END()