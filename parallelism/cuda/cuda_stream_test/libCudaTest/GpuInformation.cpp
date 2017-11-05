#include "GpuInformation.hpp"

namespace Gspp {

HardwareTargetList gpuInformation()
{
	HardwareTargetList outputList;
	int nDevices = -1;
  cudaError_t err = cudaGetDeviceCount(&nDevices);
  
  if (err == cudaSuccess){
    for (int i = 0; i < nDevices; ++i)
    {
    	cudaDeviceProp prop;
    	cudaGetDeviceProperties(&prop, i);
      HardwareTarget target;

      target.deviceNumber = i;
      target.deviceName = QString(prop.name);
      target.totalGlobalMem = prop.totalGlobalMem;
      target.sharedMemPerBlock = prop.sharedMemPerBlock;
      target.regsPerBlock = prop.regsPerBlock;
      target.warpSize = prop.warpSize;
      target.memPitch = prop.memPitch;
      target.maxThreadsPerBlock = prop.maxThreadsPerBlock;
      target.maxThreadsDimX = prop.maxThreadsDim[0];
      target.maxThreadsDimY = prop.maxThreadsDim[1];
      target.maxThreadsDimZ = prop.maxThreadsDim[2];
      target.maxGridSizeX = prop.maxGridSize[0];
      target.maxGridSizeY = prop.maxGridSize[1];
      target.maxGridSizeZ = prop.maxGridSize[2];
      target.clockRate = prop.clockRate;
      target.totalConstMem = prop.totalConstMem;
      target.major = prop.major;
      target.minor = prop.minor;
      target.textureAlignment = prop.textureAlignment;
      target.texturePitchAlignment = prop.texturePitchAlignment;
      target.deviceOverlap = prop.deviceOverlap;
      target.multiProcessorCount = prop.multiProcessorCount;
      target.kernelExecTimeoutEnabled = prop.kernelExecTimeoutEnabled;
      target.integrated = prop.integrated;
      target.canMapHostMemory = prop.canMapHostMemory;
      target.computeMode = prop.computeMode;
      target.concurrentKernels = prop.concurrentKernels;
      target.ECCEnabled = prop.ECCEnabled;
      target.pciBusID = prop.pciBusID;
      target.pciDeviceID = prop.pciDeviceID;
      target.pciDomainID = prop.pciDomainID;
      target.tccDriver = prop.tccDriver;
      target.asyncEngineCount = prop.asyncEngineCount;
      target.unifiedAddressing = prop.unifiedAddressing;
      target.memoryClockRate = prop.memoryClockRate; // KHz
      target.memoryBusWidth = prop.memoryBusWidth;  // bits
      target.l2CacheSize = prop.l2CacheSize;
      target.maxThreadsPerMultiProcessor = prop.maxThreadsPerMultiProcessor;

      outputList.append(target);
    }
  }
  return outputList;
}

std::string printGpuInformation()
{
  QString output = "";
  int nDevices = -1;
  cudaError_t err = cudaGetDeviceCount(&nDevices);
  
  if (err == cudaSuccess){
    output = output + "GPU Information\n";
    for (int i = 0; i < nDevices; ++i)
    {
      cudaDeviceProp prop;
      cudaGetDeviceProperties(&prop, i);

      output = output + "\n";
      output = output + "Device number                   : " + QString::number(i) + "\n";
      output = output + "Name                            : " + QString(prop.name) + "\n";
      output = output + "CUDA Capability version number  : " + QString::number(prop.major) + "." + QString::number(prop.minor) + "\n";
      output = output + "GPU Clock Rate                  : " + QString::number(prop.clockRate) + " Hz\n";
      output = output + "Total GPU memory                : " + QString::number(prop.totalConstMem) + " Bytes\n";
      output = output + "Memory Clock Rate               : " + QString::number(prop.memoryClockRate) + " Hz\n";
      output = output + "Memory Bus Width                : " + QString::number(prop.memoryBusWidth) + "-Bit\n";
      output = output + "Shared memory par block         : " + QString::number(prop.sharedMemPerBlock) + " Bytes\n";
      output = output + "Max thread per multi-Processor  : " + QString::number(prop.maxThreadsPerMultiProcessor) + "\n";
      output = output + "Max thread per Block            : " + QString::number(prop.maxThreadsPerBlock) + "\n";
      output = output + "Max thread Dim (x,y,z)          : " + QString::number(prop.maxThreadsDim[0]) + "," + QString::number(prop.maxThreadsDim[1]) + "," + QString::number(prop.maxThreadsDim[2]) + "\n";
      output = output + "Max Grid Size  (x,y,z)          : " + QString::number(prop.maxGridSize[0]) + "," + QString::number(prop.maxGridSize[1]) + "," + QString::number(prop.maxGridSize[2]) + "\n";
    }
  }
  return output.toStdString();
}

};