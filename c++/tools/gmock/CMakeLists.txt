cmake_minimum_required(VERSION 2.8)

project(test_gmock)

SET(Sources
  ClasseTest.cpp
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test ${Sources} test.cpp)
target_link_libraries(test ${GTEST_LIBRARIES} pthread)