#include <iostream>
#include <chrono>

//g++ -std=c++11 -S -O3 -msse3 test_sse.cpp
// -msse3 : permet la compilation du sse
// optimisation : -O3

// SSE VERSION

#define N 10000
#define NTIMES 100000
#include <time.h>
//#include <stdio.h>
#include <xmmintrin.h>
#include <pmmintrin.h>

double a[N] __attribute__((aligned(16)));
double b[N] __attribute__((aligned(16)));
double c[N] __attribute__((aligned(16)));
double r[N] __attribute__((aligned(16)));

void test_sse(){
  int i, times;
  for( times = 0; times < NTIMES; times++ ){
     for( i = 0; i <N; i+= 2){
        __m128d mm_a = _mm_load_pd( &a[i] );
        _mm_prefetch( &a[i+4], _MM_HINT_T0 );
        __m128d mm_b = _mm_load_pd( &b[i] );
        _mm_prefetch( &b[i+4] , _MM_HINT_T0 );
        __m128d mm_c = _mm_load_pd( &c[i] );
        _mm_prefetch( &c[i+4] , _MM_HINT_T0 );
        __m128d mm_r;
        mm_r = _mm_add_pd( mm_a, mm_b );
        mm_a = _mm_mul_pd( mm_r , mm_c );
        _mm_store_pd( &r[i], mm_a );
      }
   }
 }

//NO SSE VERSION
//same definitions as before
void test_simple(){
  int i, times;
   for( times = 0; times < NTIMES; times++ ){
     for( i = 0; i < N; i++ ){
      r[i] = (a[i]+b[i])*c[i];
    }
  }
}

int main(){

  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  test_simple();
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << "Simple Time : " << elapsed_seconds.count() << std::endl;

  start = std::chrono::system_clock::now();
  test_sse();
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  std::cout << "SSE    Time : " << elapsed_seconds.count() << std::endl;

	return 0;
}