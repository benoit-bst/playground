#include "main.hpp"
#include <iostream>

#include "libCudaTest/GpuStreamClass.hpp"

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
  GpuStreamClass gpuStreamClass;
  result = gpuStreamClass.process(a, b);
  gpuStreamClass.~GpuStreamClass();

  std::cout << "- a " << a << std::endl;
  std::cout << "- b " << b << std::endl;
  std::cout << "- Results " << result << std::endl;
  return 0;
}