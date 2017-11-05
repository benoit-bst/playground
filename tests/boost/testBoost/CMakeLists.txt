cmake_minimum_required(VERSION 2.8)

project(boost_test)

SET(Sources
  classe_de_test.cpp
)

find_package(Boost 1.49 REQUIRED COMPONENTS unit_test_framework)

add_executable(tests ${Sources} unit_tests.cpp)
target_link_libraries(tests ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})