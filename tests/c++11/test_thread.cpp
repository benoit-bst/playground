#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

#include <chrono>
#include <atomic>

#include <future>

using namespace std;

extern "C"{
  #include <unistd.h>
  #include <stdio.h>
}

// Thread
// compile : g++ -std=c++11 -pthread test_thread.cpp

static const int num_threads = 5;
static const int nb_process = 100000000;
static std::mutex barrier;

void testJoin();
void testFuture();
void testThreadState();
void testPromise();
void testThreadpool();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

int main()
{
  testJoin();
  testFuture();
  testThreadState();
  testPromise();
  testThreadpool();

  test1();
  test2();
  test3();
  test4();
  test5();
  test6();

  return 0;
}

//----------------------------------
//
// Test join
//
// With join "the main" wait if thread is finish
// The cout print correctly
//
//----------------------------------
void callJoin(int tid){
  std::cout << "join : " << tid << std::endl;
}

void testJoin(){

  std::cout << "------------------"<< std::endl;
  std::cout << "Test join : start"<< std::endl;

  // Single thread
  {
    std::thread t1(callJoin, 0);
    t1.join();
  }
  std::cout << "Test join : end"<< std::endl << std::endl;
}

//----------------------------------
//
// Test future
//
// wait ou get attende que le résultat soit disponible
//
//----------------------------------
int callFuture(int tid){
  std::cout << "future : " << tid << std::endl;
  sleep(3);
  return 999;
}

void testFuture(){

  std::cout << "------------------"<< std::endl;
  std::cout << "Test future : start"<< std::endl;

  // Single thread
  {
    std::future<int> answer = std::async(callFuture, 0);

    std::cout << "wait with future... answer : " << answer.get() << std::endl;
  }
  std::cout << "Test future : end"<< std::endl << std::endl;
}

//----------------------------------
//
// Test thread state
//
// wait ou get attende que le résultat soit disponible
//
//----------------------------------
int callThreadState(int tid){
  std::cout << "Active Thread" << tid << std::endl;
  sleep(5);
  return 999;
}

void testThreadState(){

  std::cout << "------------------"<< std::endl;
  std::cout << "Test thread state : start"<< std::endl;

  // Single thread
  {
    std::future<int> answer = std::async(std::launch::async, callFuture, 0);
    std::future_status status = std::future_status::timeout;

    while (status != std::future_status::ready){

      status = answer.wait_for(std::chrono::milliseconds(0));

      std::cout << "Thread still running " << (int)status << std::endl;
      sleep(1);
    }
    std::cout << "Finish, Answer : " << answer.get() << std::endl;
  }
  std::cout << "Test thread state : end"<< std::endl << std::endl;
}

//----------------------------------
//
// Test promise
//
//
//----------------------------------
void testPromise(){

  std::cout << "------------------"<< std::endl;
  std::cout << "Test promise : start"<< std::endl;


  // Single thread
  {
    promise<bool> p;
    future<bool> f = p.get_future();
    std::thread( [&p] { std::cout << "Active Thread" << std::endl;
                        std::cout << "promise" << std::endl;
                        p.set_value(true);
                        std::cout << "promise end" << std::endl;
                      } ).detach();
    f.wait();
    std::cout << "promise val : " << f.get() << std::endl;
  }


  std::cout << "Test promise : end" << std::endl;
}

//----------------------------------
//
// Test 1
//
//----------------------------------
void call_from_thread1(int tid){
  std::cout << "call_from_thread1 : " << tid << std::endl;
}

void test1(){

  std::cout << "------------------"<< std::endl;
  std::cout << "Test 1 : start"<< std::endl;

  // Single thread
  {
    std::thread t1(call_from_thread1, 0);
    t1.join();
  }

  // Pool of thread
  {
    std::thread t[num_threads];

    for (int i = 0; i < num_threads; ++i){
      t[i] = std::thread(call_from_thread1, i);
    }

    std::cout << "Launched from the main"<< std::endl;

    for (int i = 0; i < num_threads; ++i){
      t[i].join();
    }
  }
  std::cout << "Test 1 : end"<< std::endl << std::endl;
}

//----------------------------------
//
// Test 2
//
//----------------------------------
void call_from_thread2(int nb, int &result){
  // Calcul couteux
  int tmp = 0;
  for (int i = 0; i < nb; ++i){
    tmp++;
  }
  result = tmp;
}

void test2(){

  std::cout << "------------------"<< std::endl;
  std::cout << "Test 2 : start"<< std::endl;

  // Pool of thread
  {
    // Thread
    std::thread t[num_threads];
    std::vector<int> result;
    result.resize(num_threads);
    int cptSize = num_threads*nb_process;

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    for (int i = 0; i < num_threads; ++i){
      result[i] = 0;
      t[i] = std::thread(call_from_thread2, nb_process, std::ref(result[i]));
    }

    std::cout << "Launched from the main"<< std::endl;

    for (int i = 0; i < num_threads; ++i){
      t[i].join();
    }

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "test   - val    = " << cptSize << std::endl;
    std::cout << "thread - result" << std::endl;
    int count = 0;
    for (int i = 0; i < result.size(); ++i){
      std::cout << "       - result " << i << " : " << result[i] << std::endl;
      count += result[i];
    }
    std::cout << "Total  - result = " << count << std::endl;
    std::cout << "Time   - " << elapsed_seconds.count() << " seconds" << std::endl;

    // Simple
    int result2 = 0;
    start = std::chrono::system_clock::now();
    for (int i = 0; i < num_threads; ++i){
      call_from_thread2(nb_process, std::ref(result2));
    }
    std::cout << "simple - result = " << result2 << std::endl;
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    std::cout << "Time   - " << elapsed_seconds.count() << " seconds" << std::endl;
    std::cout << "Test 2 : end"<< std::endl << std::endl;
  }
}

//----------------------------------
//
// Test 3
//
//----------------------------------
void call_from_thread3(int nb, int &result){
  // Calcul couteux
  // barrier.lock();
  int tmp = 0;
  for (int i = 0; i < nb; ++i){
    tmp++;
  }
  result = tmp;
  // barrier.unlock();
}

void test3(){

  std::cout << "------------------"<< std::endl;
  std::cout << "Test 3 : start"<< std::endl;

  // Pool of thread
  {
    // Thread
    std::thread t[num_threads];
    std::vector<int> result;
    result.resize(num_threads);
    int cptSize = num_threads*nb_process;

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    for (int i = 0; i < num_threads; ++i){
      t[i] = std::thread(call_from_thread3, nb_process, std::ref(result[i]));
    }

    std::cout << "Launched from the main"<< std::endl;

    for (int i = 0; i < num_threads; ++i){
      t[i].join();
    }

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "test   - val    = " << cptSize << std::endl;
    std::cout << "thread - result" << std::endl;
    int count = 0;
    for (int i = 0; i < result.size(); ++i){
      std::cout << "       - result " << i << " : " << result[i] << std::endl;
      count += result[i];
    }
    std::cout << "Total  - result = " << count << std::endl;
    std::cout << "Time   - " << elapsed_seconds.count() << " seconds" << std::endl;

    // Simple
    int result2 = 0;
    start = std::chrono::system_clock::now();
    for (int i = 0; i < num_threads; ++i){
      call_from_thread3(nb_process, std::ref(result2));
    }
    std::cout << "simple - result = " << result2 << std::endl;
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    std::cout << "Time   - " << elapsed_seconds.count() << " seconds" << std::endl;
    std::cout << "Test 3 : end"<< std::endl << std::endl;
  }
}

//---------------------------------
//
// Test 4
//
//----------------------------------
void call_from_thread4(){
  std::cout << "Test 4 : call_from_thread4"<< std::endl;
}

void test4(){

  std::cout << "------------------"<< std::endl;
  std::cout << "Test 4 : start"<< std::endl;
  std::future<void> result(std::async(call_from_thread4));
  result.get();

  std::cout << "Test 4 : end"<< std::endl << std::endl;
}

//---------------------------------
//
// Test 5
//
//----------------------------------
void call_from_thread5(){
  std::cout << "Test 5 : call_from_thread5"<< std::endl;
}

void test5(){

  std::cout << "------------------"<< std::endl;
  std::cout << "Test 5 : start"<< std::endl;
  std::future<int> result(std::async([](int a, int b){return a+b;}, 2, 4));
  std::cout << "result " << result.get() << std::endl;

  std::cout << "Test 5 : end"<< std::endl << std::endl;
}

//---------------------------------
//
// Test 6
//
//----------------------------------
int twice(int m){
  return 2 * m;
}

void test6(){

  std::cout << "------------------"<< std::endl;
  std::cout << "Test 6 : start"<< std::endl;

  std::vector<std::future<int>> futures;

  for (int i = 0; i < num_threads; ++i){
    futures.push_back(std::async(twice, i));
  }
  for(auto &e : futures){
    std::cout << "result " << e.get() << std::endl;
  }
  std::cout << "Test 6 : end"<< std::endl << std::endl;
}