#include "GpuStreamClass.hpp"
#include "GpuInformation.hpp"

#include <iostream>

namespace GSPP {

GpuStreamClass::GpuStreamClass()
 :m_size(sizeof(int))
{
  // Hardware
   std::cout << Gspp::printGpuInformation() << std::endl;

  cudaMalloc( &m_d_a, m_size);
  cudaMalloc( &m_d_b, m_size);
  cudaMalloc( &m_d_c, m_size);
}

GpuStreamClass::~GpuStreamClass()
{
  cudaFree(m_d_a);
  cudaFree(m_d_b);
  cudaFree(m_d_c);
}

int GpuStreamClass::process(int & a, int & b)
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