extern "C"
{
  #include <sys/resource.h>
  #include <sys/sysinfo.h>
  #include <unistd.h>
  #include <errno.h>
}

// STL
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

/**
 *  compile : g++ sysinfoTest.cpp
 *
 */
int main(int argc, char const *argv[])
{
  struct sysinfo nfo;
  sysinfo(&nfo);

  unsigned long totalRam = nfo.totalram * nfo.mem_unit;
  std::cout << "totalRam : " << totalRam << std::endl;

  unsigned long freeRam = nfo.freeram * nfo.mem_unit;
  std::cout << "freeRam  : " << freeRam << std::endl;

  unsigned long procs = nfo.procs;
  std::cout << "procs    : " << procs << std::endl;

  std::ifstream infile("/proc/stat");
  std::string line;

  unsigned long cpuUser;
  unsigned long cpuUserLow;
  unsigned long cpuSys;
  unsigned long cpuIdle;
  unsigned long cpuWait;

  std::getline(infile, line);
  sscanf(line.c_str(),
          "cpu  %20Ld %20Ld %20Ld %20Ld %20Ld",
          &cpuUser,
          &cpuUserLow,
          &cpuSys,
          &cpuIdle,
          &cpuWait);

  std::cout << "Total CPU - CPU User : " << cpuUser << " - cpuUserLow : " << cpuUserLow << " - cpuSys : " << cpuSys << " - cpuIdle : " << cpuIdle << " - cpuWait : " << cpuWait << std::endl;

  // on balaye toutes les lignes
  while (std::getline(infile, line))
  {
    std::cout << "Line proc/stat : " << line << std::endl;
  }

  return 0;
}