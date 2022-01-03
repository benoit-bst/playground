cmake_minimum_required(VERSION 2.8)

SET(MAIN_SOURCES
  main.cpp
  MyThread.cpp
)

SET(MAIN_HEADERS
  main.hpp
  MyThread.hpp
)

# QT
find_package(Qt4 4.6.0 COMPONENTS QtCore REQUIRED)
include(${QT_USE_FILE})

# Obligatiore avec l'utilisation de QObject	
qt4_wrap_cpp(MAIN_MOC ${MAIN_HEADERS})

add_executable(test_QThread ${MAIN_SOURCES} ${MAIN_MOC})

target_link_libraries(test_QThread ${QT_LIBRARIES})
