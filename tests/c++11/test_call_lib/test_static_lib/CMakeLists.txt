cmake_minimum_required(VERSION 2.8)

# Project
project( staticTest )

# Version
set(MAJOR 1)
set(MINOR 0)
set(PATCH 0)
set(VERSION ${MAJOR}.${MINOR}.${PATCH})

# Sources
SET(LIB_STATIC_TEST_SOURCES
  File1.cpp
  File2.cpp
)

SET(LIB_STATIC_TEST_HEADERS
  File1.hpp
  File2.hpp
)

# Create library
add_library(staticTest STATIC ${LIB_STATIC_TEST_SOURCES})

