#include "GpuTestClass.hpp"
#include <iostream>

namespace GSPP {

GpuTestClass::GpuTestClass()
 :m_size(sizeof(int))
{
  // Hardware
  int nDevices = -1;
  cudaGetDeviceCount(&nDevices);
  std::cout << "Nb Device   : " << nDevices << std::endl;

  cudaDeviceProp prop;
  cudaGetDeviceProperties(&prop, 0);
  std::cout << "Device name : " << prop.name << std::endl;

  cudaMalloc( &m_d_a, m_size);
  cudaMalloc( &m_d_b, m_size);
  cudaMalloc( &m_d_c, m_size);
}

GpuTestClass::~GpuTestClass()
{
  cudaFree(m_d_a);
  cudaFree(m_d_b);
  cudaFree(m_d_c);
}

int GpuTestClass::process(int & a, int & b)
{
  int c = 0;

  // Copy data
  cudaMemcpy(m_d_a, &a, m_size, cudaMemcpyHostToDevice);
  cudaMemcpy(m_d_b, &b, m_size, cudaMemcpyHostToDevice);

  // Launch add() on GPU
  GPU_KERNEL::add_gpu(m_d_a, m_d_b, m_d_c);

  // Copy result back to host
  cudaMemcpy(&c, m_d_c, m_size, cudaMemcpyDeviceToHost);

  return c;
}

};