#ifndef _GSPP_GPU_INFORMATION_HPP_
#define _GSPP_GPU_INFORMATION_HPP_

#include <cuda.h>
#include <cuda_runtime.h>
#include <QList>
#include <QString>
#include <string>

namespace Gspp {

/**
  * Structure HardwareTarget
  * Cette structure contient tout la configuratio hard du GPU
  les paramètres les plus importants sont :
  * deviceNumber : le nombre de GPU détecté
  * deviceName : Le nom du GPU
  * totalGlobalMem : La mémoire totale du GPU (Bytes)
  * sharedMemPerBlock : La mémoire partagé par block (Bytes)
  * maxThreadsPerBlock : Le nombre de thread max par block
  * maxThreadsPerMultiProcessor : Le nombre de thread par multi-processeur
  * maxThreadsDimX : Le nombre de thred max sur la dim X
  * maxThreadsDimY : Le nombre de thred max sur la dim Y
  * maxThreadsDimZ : Le nombre de thred max sur la dim Z
  * maxGridSizeX : La taille max de grille sur X
  * maxGridSizeY : La taille max de grille sur Y
  * maxGridSizeZ : La taille max de grille sur Z
  * memoryClockRate : La vitesse d'horloge pour l'accès mémoire (KHz)
  * memoryBusWitdh : La largeur du bus mémoire (bits)
  */
struct HardwareTarget
{
  int deviceNumber;
  QString deviceName;
  size_t totalGlobalMem;
  size_t sharedMemPerBlock;
  int regsPerBlock;
  int warpSize;
  size_t memPitch;
  int maxThreadsPerBlock;
  int maxThreadsDimX;
  int maxThreadsDimY;
  int maxThreadsDimZ;
  int maxGridSizeX;
  int maxGridSizeY;
  int maxGridSizeZ;
  int clockRate;
  size_t totalConstMem;
  int major;
  int minor;
  size_t textureAlignment;
  size_t texturePitchAlignment;
  int deviceOverlap;
  int multiProcessorCount;
  int kernelExecTimeoutEnabled;
  int integrated;
  int canMapHostMemory;
  int computeMode;
  int concurrentKernels;
  int ECCEnabled;
  int pciBusID;
  int pciDeviceID;
  int pciDomainID;
  int tccDriver;
  int asyncEngineCount;
  int unifiedAddressing;
  int memoryClockRate; // KHz
  int memoryBusWidth;  // bits
  int l2CacheSize;
  int maxThreadsPerMultiProcessor;
};

typedef QList<HardwareTarget> HardwareTargetList;

/**
  * La fonction de traitement renvoit une liste de structure HardwareTarget,
  * qui contient les paramètres de chaque carte GPU.
  * @attention Si la structure est vide alors aucune carte n'est détectée.
  */
HardwareTargetList gpuInformation();

/**
  * Renvoit une std::string contenant les informations les plus importantes
  * @attention Si aucune carte n'est détectée alors la chaine est vide.
  */
std::string printGpuInformation();

};

#endif // _GSPP_GPU_INFORMATION_HPP_