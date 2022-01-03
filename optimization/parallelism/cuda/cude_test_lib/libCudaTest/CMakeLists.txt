cmake_minimum_required(VERSION 2.8)

find_package(CUDA)

# Version
set(MAJOR 1)
set(MINOR 0)
set(PATCH 0)
set(VERSION ${MAJOR}.${MINOR}.${PATCH})

# Sources
SET(KERNEL_SOURCES
  kernel/kernel_gpu.cu
)

SET(KERNEL_HEADERS
  kernel/kernel_gpu.h
)

# Sources
SET(LIB_CUDA_TEST_SOURCES
  GpuTestClass.cpp
)

SET(LIB_CUDA_TEST_HEADERS
  GpuTestClass.hpp
)

cuda_add_library( kernel_lib ${KERNEL_SOURCES} ${KERNEL_HEADERS})

add_library( CudaTest STATIC ${LIB_CUDA_TEST_SOURCES})
target_link_libraries(CudaTest kernel_lib)