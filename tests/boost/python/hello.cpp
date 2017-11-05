#include <boost/python.hpp>

/**
 * g++ -I /usr/include/python2.7 -lpython2.7 -lboost_python python.cpp
 */

char const* greet(){
  return "hello world";
}

BOOST_PYTHON_MODULE(hello)
{
  using namespace boost::python;
  def("greet", greet);
}