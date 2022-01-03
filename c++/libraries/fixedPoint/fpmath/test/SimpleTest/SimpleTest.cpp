#include "SimpleTest.hpp"

QTEST_MAIN(SimpleTest)

void SimpleTest::scenario1()
{
  fpml::fixed_point<int, 16, 2> a = 256.;
  fpml::fixed_point<int, 16, 2> b = sqrt(a);
}