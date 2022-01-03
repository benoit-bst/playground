#include <iostream>

#include <chrono>

#include <vector>
#include <tbb/tbb.h>
#include <tbb/parallel_for.h>
#include <tbb/atomic.h>

// Tbb
// g++ -std=c++11 -ltbb test_tbb.cpp


void test1();
void test2();
void test3();
void test4();

int main()
{
  test1();
  test2();
  test3();
  test4();
}

//----------------------------------------
// Test 1 : simple test
//----------------------------------------
class ZeroCounter
{
public :
  ZeroCounter(std::vector<int> * vec, tbb::atomic< int > * count) :
    vec(vec),
    count(count)
  {}
  
  void operator()(int index) const
  {
    if ((*vec)[index] == 0)
      ++(*count);
  }
  
  std::vector<int> * vec;
  tbb::atomic<int> * count;
};

void test1()
{
  std::cout << "---------------------------------------" << std::endl;
  
  std::cout << "-- Test 1 : Creation du vecteur de test" << std::endl;
  std::vector<int> a;
  a.push_back(0);
  a.push_back(3);
  a.push_back(0);
  for (int i = 0; i < 200000000; ++i){
  a.push_back(0);
  }
  
  tbb::atomic< int > count;
  count = 0;
  
  // Simple
  std::chrono::time_point<std::chrono::system_clock> start, end; 
  start = std::chrono::system_clock::now();
  float tmp = 1;
  for (int i = 0; i < 200000000; ++i){
    if (a[i] == 0)
      tmp++;
  }
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::cout << "Time Simple  - " << elapsed_seconds.count() << " seconds" << std::endl;
  
  std::cout << "Creation de l'objet" << std::endl;
  ZeroCounter counter(&a, &count);
  
  std::cout << "Lancement parallel_for" << std::endl;
  start = std::chrono::system_clock::now();
  tbb::parallel_for(size_t(0), a.size(), counter);
  end = std::chrono::system_clock::now();
  elapsed_seconds = end - start;
  std::cout << "Time tbb     - " << elapsed_seconds.count() << " seconds" << std::endl;
  
  std::cout << count << std::endl;
  
}

//----------------------------------------
// Test 2 : tbb parallel_for
//----------------------------------------
class classCoeurCalcul
{
  
  public:
    classCoeurCalcul(float * a, std::vector<float> * output ) :
      m_buffer(a),
      m_ouput(output)
    {}
    
    void operator()(const tbb::blocked_range<size_t>& r) const
    {
      float *a = m_buffer;
      for (size_t i = r.begin(); i != r.end(); ++i){
        (*m_ouput)[i] = a[i] * a[i];
        a[i] = a[i] * a[i];
      }
    }
    
  private:
    
    float * m_buffer;
    std::vector<float> * m_ouput;
};

void test2()
{
  std::cout << "---------------------------------------" << std::endl;
  
  std::cout << "-- Test 2 : Creation du vecteur de test" << std::endl;
  std::vector<float> input;
  for (int i = 0; i < 20000000; ++i){
    input.push_back(2);
  }
  std::vector<float> output;
  output.resize(20000000);
  
  
  // Simple
  std::chrono::time_point<std::chrono::system_clock> start, end; 
  start = std::chrono::system_clock::now();
  float tmp = 1;
  for (int i = 0; i < 20000000; ++i){
    tmp = tmp * tmp;
    tmp = tmp * tmp;
  }
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::cout << "Time Simple  - " << elapsed_seconds.count() << " seconds" << std::endl;

  std::cout << "Lancement parallel_for" << std::endl;
  start = std::chrono::system_clock::now();
  tbb::parallel_for(tbb::blocked_range<size_t>(0,input.size()), classCoeurCalcul(input.data(), &output));
  end = std::chrono::system_clock::now();
  elapsed_seconds = end - start;
  std::cout << "Time tbb     - " << elapsed_seconds.count() << " seconds" << std::endl;
  
}

//----------------------------------------
// Test 3 : tbb Calcul de la moyenne
//----------------------------------------
class classParallelMeam
{
  public:
    classParallelMeam(float * const input, tbb::atomic< float > * result) :
      m_input(input),
      m_result(result)
    {}
    
    void operator()(const tbb::blocked_range<size_t>& r) const
    {
      float tmp = 0;
      int count = 0;
      for (int i = r.begin(); i != r.end(); ++i){
	      tmp += m_input[i];
	      count++;
      }
      (*m_result) = tmp/count;
    }

    void restart()
    {
      m_result = 0;
    }
    
    tbb::atomic<float> * results(){return m_result;}
    
  private:
    float * m_input;
    tbb::atomic<float> * m_result;
};

void parallelMeam(float * const input, int n, float * result)
{
  float tmp = 0;
  for (int i = 0; i < n; ++i){
    tmp += input[i];
  }
  (*result) = tmp/n;
}

void test3()
{
  std::cout << "---------------------------------------" << std::endl;
  
  // Signal
  std::cout << "-- Test 3 : Creation du vecteur de test" << std::endl;
  std::vector<float> input;
  for (int i = 0; i < 2000000; ++i){
    input.push_back(2);
  }
  
  // Simple
  std::cout << "Test simple" << std::endl;
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  float res = 0;
  parallelMeam(input.data(), input.size(), &res);
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::cout << "Time Simple  - " << elapsed_seconds.count() << " seconds - Mean : " << res << std::endl;

  // parallel_for
  tbb::atomic< float > count;
  count = 0;
  std::cout << "Lancement parallel_for" << std::endl;
  start = std::chrono::system_clock::now();
  tbb::parallel_for(tbb::blocked_range<size_t>(0,input.size()), classParallelMeam(input.data(), &count));
  end = std::chrono::system_clock::now();
  elapsed_seconds = end - start;
  std::cout << "Time tbb     - " << elapsed_seconds.count() << " seconds - Mean : " << count << std::endl;
}

//----------------------------------------
// Test 4 : tbb parallel_reduce
//----------------------------------------
class classTest4
{
  public:
    classTest4(float * a):
      m_buffer(a),
      m_sum(0)
    {}
    
    classTest4( classTest4& x, tbb::split ) : 
      m_buffer(x.m_buffer), 
      m_sum(0) 
    {}
    
    void operator()(const tbb::blocked_range<size_t>& r) const
    {
      float *a = m_buffer;
      float tmp = 0;
      for (size_t i = r.begin(); i != r.end(); ++i){
         tmp = a[i] * a[i];
	       tmp = a[i] * a[i];
      }
      m_sum = tmp;
    }
    
    void join(const classTest4& y) {m_sum += y.m_sum; }
   private: 
    float * m_buffer;
    float m_sum;
};

void test4()
{
  std::cout << "---------------------------------------" << std::endl;
  // Le parallel_reduce gère la decoupe des bouts de signal en portion modulo
  const int signalLength = 20000000;
  
  std::cout << "-- Test 4 : Creation du vecteur de test" << std::endl;
  std::vector<float> input;
  for (int i = 0; i < signalLength; ++i){
    input.push_back(2);
  }
  std::vector<float> output;
  output.resize(signalLength);
  
  // Simple
  std::chrono::time_point<std::chrono::system_clock> start, end; 
  start = std::chrono::system_clock::now();
  float tmp = 1;
  for (int i = 0; i < signalLength; ++i){
    tmp = tmp * tmp;
    tmp = tmp * tmp;

  }
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::cout << "Time Simple  - " << elapsed_seconds.count() << " seconds" << std::endl;

  // parallel_reduce
  std::cout << "Lancement parallel_reduce" << std::endl;
  classTest4 classtest(input.data());
  start = std::chrono::system_clock::now();
  tbb::parallel_reduce(tbb::blocked_range<size_t>(0,input.size()), classtest);
  end = std::chrono::system_clock::now();
  elapsed_seconds = end - start;
  std::cout << "Time tbb     - " << elapsed_seconds.count() << " seconds" << std::endl;
}
