#include <iostream>
#include <chrono>

// g++ -std=c++11 loopTiling.cpp
// Principe d'optimisation lien à la taille du cache CPU
// On découpe les boucles en blocs de taille des registres

// Il faut calculer la taille optimal de travail en fonction du cache
// Exemple : L1 = 8KB (8*1024=8192) - Size line = 64 bytes
//

#define MAX (1024*1024)
#define REP 1000
#define BLOCK_SIZE 8192 // 16384 32768

int main(){

  int i, j, r;
  char array[MAX];

  //---------------------------------------
  // Warm Up to make things equal if array
  // happens to fit in your glVertexAttribL3d();
  //---------------------------------------
  for (int i = 0; i < MAX; ++i)
  {
    array[i] = 0;
  }

  //---------------------------------------
  // Tiled-loop
  //---------------------------------------
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();

  for (int i = 0; i < MAX; i += BLOCK_SIZE)
  {
    for (int r = 0; r < REP; ++r)
    {
      for (int j = i; j < (i + BLOCK_SIZE); j+=64)
      {
        array[j] = r;
      }
    }
  }

  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << "Tiled loop         : " << elapsed_seconds.count() << std::endl;

  //---------------------------------------
  // Un-Tiled-loop
  //---------------------------------------
  start = std::chrono::system_clock::now();

  for (int r = 0; r < REP; ++r)
  {
    for (int i = 0; i < MAX; i+=64)
    {
        array[i] = r;
    }
  }

  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  std::cout << "Un-tiled lopp      : " << elapsed_seconds.count() << std::endl;

  return 0;
}
