cmake_minimum_required(VERSION 2.8)

SET(MAIN_SOURCES
  main.cpp
)

SET(MAIN_HEADERS
  main.hpp
)

add_subdirectory(test_shared_lib)

add_executable(test ${MAIN_SOURCES})

target_link_libraries(test sharedTest)