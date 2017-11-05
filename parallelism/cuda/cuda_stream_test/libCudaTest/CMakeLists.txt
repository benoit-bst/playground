cmake_minimum_required(VERSION 2.8)

find_package(CUDA)

# QT
find_package(Qt4 4.6.0 COMPONENTS QtCore REQUIRED)
include(${QT_USE_FILE})

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
  GpuStreamClass.cpp
  GpuInformation.cpp
)

SET(LIB_CUDA_TEST_HEADERS
  GpuStreamClass.hpp
  GpuInformation.hpp
)

cuda_add_library( kernel_lib ${KERNEL_SOURCES} ${KERNEL_HEADERS})

add_library( CudaTest STATIC ${LIB_CUDA_TEST_SOURCES})
target_link_libraries(CudaTest kernel_lib ${QT_LIBRARIES} )