cmake_minimum_required (VERSION 2.6)
project (simpletest)

find_package(Qt4 4.6.3 COMPONENTS QtCore QtTest REQUIRED)
include(${QT_USE_FILE})

unset( MOC_SOURCES)
qt4_wrap_cpp( MOC_SOURCES SimpleTest.hpp)
add_executable( SimpleTest SimpleTest.cpp ${MOC_SOURCES})
target_link_libraries( SimpleTest ${QT_LIBRARIES})