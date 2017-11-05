#include <iostream>
#include "instrSet/InstrSet.hpp"

typedef __m128i base_type;

/**
 * Le site de référence :
 * https://software.intel.com/sites/landingpage/IntrinsicsGuide
 *
 *
 * g++ -O3 -msse3 -mavx -mavx2 -mfma instrSet/InstrSet.cpp Simd128Tests.cpp
 */
int main(int argc, char const *argv[])
{
  {
    std::cout << "Size of m128 (x8 - Bytes) : " << sizeof(__m128i) << std::endl;

    base_type val1;
    base_type val2;

    val1 = _mm_setzero_si128();        // set the 128 bits value to zero
    val1 = _mm_set1_epi32(2);          // add x4 input val
    val1 = _mm_setr_epi32(1,2,3,4);    // add 4 input

    val2 = _mm_setzero_si128();        // set the 128 bits value to zero
    val2 = _mm_set1_epi32(2);          // add x4 input val
    val2 = _mm_setr_epi32(1,2,3,4);    // add 4 input

    base_type res = val1 + val2;

    int tab[4];
    tab[0] = 1;
    tab[1] = 1;
    tab[2] = 1;
    tab[3] = 1;

    // On check si la data est aligné sur 16 Bytes (mod de la val du pointer)
    int *p = tab;
    size_t i = (size_t)p;
    std::cout << "Aligned : " << ((i%16) == 0) << std::endl;

    // load vect in _m128i
    // memory have to be aligned
    val1 = _mm_loadu_si128((base_type*)tab);

    // load vect in _m128i
    // memory have to be aligned
    val1 = _mm_load_si128((base_type*)tab);


    // Recupère les val
    // memory have to be aligned
    int tabRes[4];
    tabRes[0] = 0;
    tabRes[1] = 0;
    tabRes[2] = 0;
    tabRes[3] = 0;
    std::cout << "Data Res Before : " << tabRes[0] << tabRes[1] << tabRes[2] << tabRes[3] << std::endl;
    _mm_storeu_si128((base_type*)tabRes, val1);
    std::cout << "Data Res after  : " << tabRes[0] << tabRes[1] << tabRes[2] << tabRes[3] << std::endl;

    // Recupère les val
    int tabRes2[4];
    tabRes2[0] = 0;
    tabRes2[1] = 0;
    tabRes2[2] = 0;
    tabRes2[3] = 0;
    std::cout << "Data Res Before : " << tabRes2[0] << tabRes2[1] << tabRes2[2] << tabRes2[3] << std::endl;
    _mm_store_si128((base_type*)tabRes2, val1);
    std::cout << "Data Res after  : " << tabRes2[0] << tabRes2[1] << tabRes2[2] << tabRes2[3] << std::endl;

  }

  {
     // add adjacent pairs of 32-bit integers
     // Used for reduction
#if  INSTRSET >= 4  // SSSE3

      base_type val1;
      base_type val2;
      int tabRes[4];

      val1 = _mm_setr_epi32(1,2,3,4);
      val2 = _mm_setr_epi32(1,2,3,4);

      base_type res = _mm_hadd_epi32(val1,val2);
      _mm_storeu_si128((base_type*)tabRes, res);

      std::cout << "Data Res after  : " << tabRes[0] << tabRes[1] << tabRes[2] << tabRes[3] << std::endl;

#endif
  }


  {
     // Compare packed 32-bit integers for equality
     // -1 if equal else 0

      base_type val1;
      base_type val2;
      int tabRes[4];

      val1 = _mm_setr_epi32(1,2,3,4);
      val2 = _mm_setr_epi32(12,10,3,4);

      base_type res = _mm_cmpeq_epi32(val1,val2);
      _mm_storeu_si128((base_type*)tabRes, res);

      std::cout << "Data cmp  : " << tabRes[0] << tabRes[1] << tabRes[2] << tabRes[3] << std::endl;

  }

  {
   // Blend elements
#if  INSTRSET >= 5  // SSE4.1

    // in
    __m128 val1 = _mm_castsi128_ps( _mm_setr_epi32(1,1,1,1) );
    __m128 val2 = _mm_castsi128_ps( _mm_setr_epi32(2,2,2,2) );
    const int mask = 0x3;

    // blend
    __m128 res = _mm_blend_ps(val1, val2, mask); // 2211
    base_type resi = _mm_castps_si128(res);

    // Out
    int tabRes[4];
    _mm_storeu_si128((base_type*)tabRes, resi);

    std::cout << "Data blend : " << tabRes[0] << tabRes[1] << tabRes[2] << tabRes[3] << std::endl;

#endif
  }

  return 0;
}