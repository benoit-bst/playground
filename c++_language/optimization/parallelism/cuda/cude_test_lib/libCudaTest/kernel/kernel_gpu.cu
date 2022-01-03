#include "kernel_gpu.h"

#include <cuda.h>
#include <cuda_runtime.h>
#include <iostream>

namespace GPU_KERNEL
{

namespace internal
{

__global__ void add_internal(int *a, int *b, int *c)
{
  *c = *a + *b;
}

};

void add_gpu(int *a, int *b, int *c)
{
  internal::add_internal<<<1,1>>>(a, b, c);
}

};