/*

 gcc offre un intermediaire entre l'assembleur et le C
 SIMD : Single Instruction, Multiple Data
 Les instructions SSE sont dépendantes de l'architecture processeur (Ex: AVX en Intel Core I7).

 MMX   (Multimedia extension)       - mmintrin.h              - 64 Bits  - gcc flag -mmmx
 SSE   (Streaming SIMD extension)   - xmmintrin.h             - 128 Bits - gcc flag -msse
 SSE2  (Streaming SIMD extension)   - emmintrin.h             - 128 Bits - gcc flag -msse2
 SSE3  (Streaming SIMD extension)   - pmmintrin.h             - 128 Bits - gcc flag -msse3
 SSSE3 (Streaming SIMD extension)   - tmmintrin.h             - 128 Bits - gcc flag -mssse3
 SSE4  (Streaming SIMD extension)   - smmintrin.h nmmintrin.h - 128 Bits - gcc flag -msse4
 AVX   (Advanced vector extensions) - immintrin.h             - 256 Bits - gcc flag -mavx

 On trouve les instructions AVX dans la lib de traitement intel MKL...

 compilation des exemples :
 g++ -mavx -mavx2 simd_test.cpp

*/

#include <iostream>

extern "C" {
  #include <immintrin.h>
}

#include "instrSet/InstrSet.hpp"

int main() {

  /***********************************************

    AVX - Exemple simple

  ***********************************************/
  {
    __m256 ymm0, ymm1; // Define the registers used

    float a[8] = {1,2,3,4,5,6,7,8};
    float b[8] = {2,3,4,5,6,7,8,9};

    __m256 a;
    _mm_l

    float c[8];

    ymm0 = __builtin_ia32_loadups256(a); // load the 8 floats in a into ymm0
    ymm1 = __builtin_ia32_loadups256(b); // load the 8 floats in a into ymm1

    // Multiply ymm0 abd ymm1, store the result in ymm0
    ymm0 = __builtin_ia32_mulps256(ymm0, ymm1);
    __builtin_ia32_storeups256(c, ymm0); // copy the 8 float in ymm0 to c

    for (int i = 0; i < 8; ++i)
    {
      std::cout << c[i] << ", ";
    }
    std::cout << std::endl;
  }

  /***********************************************

    AVX - Exemple simple

  ***********************************************/
  {
    __m256i a;
    __m256i b;
    __m256i ymm0 = _mm256_cmpeq_epi8( a, b );

  }


  return 0;
}