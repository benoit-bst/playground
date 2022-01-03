#ifndef _GSPP_TEST_HPP_
#define _GSPP_TEST_HPP_

#include <cuda.h>
#include <cuda_runtime.h>
#include "kernel/kernel_gpu.h"

namespace GSPP {

/**
 * @class class de test
 */
class GpuStreamClass
{
  public: 
    
    GpuStreamClass();
    ~GpuStreamClass();
    
    int process(int & a, int & b);
  private:

    int *m_d_a; 
    int *m_d_b; 
    int *m_d_c;
    int m_size;
};

};

#endif // _GSPP_TEST_HPP_
