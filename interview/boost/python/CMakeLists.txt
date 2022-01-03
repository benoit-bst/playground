cmake_minimum_required(VERSION 2.8.3)

# Found Python
find_package(PythonInterp)
find_package(PythonLibs)
find_package(Boost COMPONENTS python)


include_directories( ${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS} )
link_libraries( ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} )

# Add modules
PYTHON_ADD_MODULE(hello hello.cpp)
FILE(COPY hello.py DESTINATION .)