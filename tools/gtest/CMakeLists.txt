cmake_minimum_required(VERSION 2.8)

project(test_gtest)

SET(Sources
  classe_de_test.cpp
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests ${Sources} unit_tests.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)