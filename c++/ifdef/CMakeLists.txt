cmake_minimum_required(VERSION 2.8)

SET(MAIN_SOURCES
  main.cpp
)

option(TOTO "Active toto" ON)
if (TOTO)
  add_definitions(-DTOTO)
endif()

add_executable(test ${MAIN_SOURCES})
