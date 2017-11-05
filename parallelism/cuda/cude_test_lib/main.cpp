#include "main.hpp"
#include <iostream>

#include "libCudaTest/GpuTestClass.hpp"

using namespace GSPP;

/*
 * compile : nvcc -o name_applis source.cu
 */
int main(int argc, char* argv[])
{
  int a = 10;
  int b = 10;
  int result = 0;

  // Launch add() on GPU
  GpuTestClass gpuTestClass;
  result = gpuTestClass.process(a, b);
  gpuTestClass.~GpuTestClass();

  std::cout << "- a " << a << std::endl;
  std::cout << "- b " << b << std::endl;
  std::cout << "- Results " << result << std::endl;
  return 0;
}