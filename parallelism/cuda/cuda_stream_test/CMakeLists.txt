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
)

SET(MAIN_HEADERS
  main.hpp
)

# Insertion lib cuda
add_subdirectory(libCudaTest)

add_executable(cuda_stream_test ${MAIN_SOURCES})
target_link_libraries(cuda_stream_test CudaTest)
