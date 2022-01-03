cmake_minimum_required(VERSION 2.8)

# Project
project( sharedTest )

# Version
set(MAJOR 1)
set(MINOR 0)
set(PATCH 0)
set(VERSION ${MAJOR}.${MINOR}.${PATCH})

# Sources
SET(LIB_SHARED_TEST_SOURCES
  File1.cpp
  File2.cpp
)

SET(LIB_SHARED_TEST_HEADERS
  File1.hpp
  File2.hpp
)

# create library
add_library(sharedTest SHARED ${LIB_SHARED_TEST_SOURCES})

# Add version in library name
set_target_properties(${PROJECT_NAME} PROPERTIES
                      SOVERSION ${MAJOR}.${MINOR}
                      VERSION   ${VERSION})