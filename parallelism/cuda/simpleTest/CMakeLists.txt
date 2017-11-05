cmake_minimum_required(VERSION 2.8)

find_package(CUDA)

if(CUDA_FOUND)
  message(STATUS "Presence CUDA")
  ADD_DEFINITIONS(-DCUDA_FOUND)
  SET(CUDA_VERBOSE_BUILD ON)
  SET(CUDA_BUILD_CUBIN ON)
  SET(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS} -lcudart -lcufft -O3 -use_fast_math -arch=compute_20 -code=sm_20,sm_30,sm_35)
else()
  message(STATUS "Pas de CUDA")
endif()

SET(MAIN_SOURCES
  main.cpp
  kernel_gpu.cu
)

SET(MAIN_HEADERS
  main.hpp
  kernel_gpu.h
)

cuda_add_executable(test_cuda ${MAIN_SOURCES})