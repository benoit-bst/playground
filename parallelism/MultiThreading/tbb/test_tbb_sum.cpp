#include <iostream>

#include <chrono>

#include <vector>
#include <tbb/tbb.h>
#include <tbb/parallel_for.h>
#include <tbb/atomic.h>

// g++ -std=c++11 -ltbb test_tbb.cpp
class Sum
{
public:
  Sum(): m_sum(0) {}
  Sum( Sum& x, tbb::split ): m_sum(0) {}

  void operator()(const tbb::blocked_range<float*>& r)
  {
    float tmp = m_sum;
    for (float* a = r.begin(); a != r.end(); ++a){
      tmp += *a;
    }
    m_sum = tmp;
  }

  void join(const Sum& y) {m_sum += y.m_sum; }

  float result(){return m_sum;}

private:
    float m_sum;
};

float parallelSum(float array[], size_t n)
{
  Sum total;
  tbb::parallel_reduce(tbb::blocked_range<float*>(array, array+n, 1000), total);
  return total.result();
}

float sum(float array[], size_t n)
{
  float tmp = 0;
  for (int i = 0; i < n; ++i){
    tmp += array[i];
  }
  return tmp;
}

int main()
{
  //----------------------------------------------------------------------------
  // Example Sum : parallel_reduce
  //----------------------------------------------------------------------------
  {
    // Le parallel_reduce gère la découpe des bouts de signal en portion modulo
    const int signalLength = 15000000;

    // Création du signal
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Creation du vecteur de test" << std::endl;
    std::vector<float> input;
    for (int i = 0; i < signalLength; ++i){
      input.push_back(1);
    }
    std::vector<float> output;
    output.resize(signalLength);

    // Simple
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    float sum1 = sum(input.data(), input.size());
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Time Simple  - " << elapsed_seconds.count() << " seconds - Mean : " << sum1 << std::endl;

    // parallel_reduce
    std::cout << "Lancement parallel_reduce" << std::endl;
    start = std::chrono::system_clock::now();
    float sum2 = parallelSum(input.data(), input.size());
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    std::cout << "Time tbb     - " << elapsed_seconds.count() << " seconds - Mean : " << sum2 << std::endl;
  }
  return 0;
}