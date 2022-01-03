#include "main.hpp"
#include <iostream>

#include <cuda.h>
#include <cuda_runtime.h>
#include "kernel_gpu.h"

/*
 * compile : nvcc -o name_applis source.cu
 */
int main(int argc, char* argv[])
{
  // Hardware
  int nDevices = -1;
  cudaGetDeviceCount(&nDevices);
  std::cout << "Nb Device   : " << nDevices << std::endl;

  cudaDeviceProp prop;
  cudaGetDeviceProperties(&prop, 0);
  std::cout << "Device name : " << prop.name << std::endl;

  // Host Var
  int a = 10;
  int b = 10;
  int c = 0;
  int size = sizeof(int);

  //Device copies of a b c
  int *d_a, *d_b, *d_c;

  // Allocation memoire sur device of a, b ,c
  cudaMalloc( &d_a, size);
  cudaMalloc( &d_b, size);
  cudaMalloc( &d_c, size);

  // Copy data
  cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, &b, size, cudaMemcpyHostToDevice);

  // Launch add() on GPU
  add_gpu(d_a, d_b, d_c);

  // Copy result back to host
  cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);

  std::cout << "- a " << a << std::endl;
  std::cout << "- b " << b << std::endl;
  std::cout << "- Results " << c << std::endl;

  // cleanuo
  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);

  return 0;
}