#include <iostream>
#include <cmath>

/**
 * perf tools 3.2
 *
 * Pour avoir le code C++ compiler avec l'option -g
 * Le compilateur store symbol table information.
 * Names of variables functions, line numbers
 *
 * perf_3.2 record -g ./prog args
 * resultats dans perf.data
 *
 * perf_3.2 report --stdio --sort comm,dso
 * perf_3.2 report --stdio --dsos=libDsppModemTools.so.0.5.0
 * perf_3.2 report -n --stdio
 *
 * Stat :
 * perf_3.2 stat prog args
 *
 * perf_3.2 top
 */

 /**
 * valgrind callgrind
 *
 * Pour avoir le code C++ compiler avec l'option -g
 * Le compilateur store symbol table information. Disable optimizations
 * Names of variables functions, line numbers
 *
 * valgrind --tool=callgrind a.out
 * kcachegrind callgrind.out.245652
 */

 /**
 * gprof
 *
 *  g++ -pg perfTest.cpp
 *  run : ./a.out
 *  gprof a.out gmon.out > analysis
 */

/*
 * compile : g++ -g perfTest.cpp
 *
 */

 void function11(){
  for (int i = 0; i < 10000; ++i)
  {
    float r = 1.2;
    float b = 0;
    float f = r + b;
  }
}

 void function1(){
   int a = 0;
   int b = 10;
   for (int i = 0; i < 1000; ++i)
   {
      int c = 0;
      a += 3 + b + std::sqrt(3.2);
      function11();
   }
 }

 void function2(){
  int a = 0;
  int b = 10;
  for (int i = 0; i < 1000000; ++i)
  {
    int c = 0;
    a += 3 + b;
  }
 }

int main(int argc, char const *argv[])
{
  function1();
  function2();

  return 0;
}