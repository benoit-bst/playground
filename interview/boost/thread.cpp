#include <iostream>
// #include <thread>
#include <boost/thread.hpp>
#include <boost/bind.hpp>

extern "C"{
  #include <unistd.h>
  #include <stdio.h>
}

using namespace std;


// Thread
// compile : g++ -std=c++0x-lboost_system -lboost_thread threadState.cpp

// void callJoin(int * a){

//   std::cout << "join : " << std::endl;

//   // Loop
//   int localCounter = 0;
//   while(localCounter < 3){
//     localCounter++;
//     sleep(2);
//   }
//   cout << "thread's end "<< endl;

//   *a = 1;
// }



int main()
{
  // Single thread
  // {
  //   int in1 = 0;
  //   boost::thread t1(callJoin, &in1);
  //   t1.detach();

  //   int in2 = 0;
  //   boost::thread t2(callJoin, &in2);
  //   t2.detach();

  //   while(1){
  //     cout << "t1 = " << in1 << endl;
  //     cout << "t2 = " << in2 << endl;
  //     sleep(1);
  //   }

  // }

  {
  	class Task
		{
      private:
      	volatile int *m_a;

		  public:
		    Task(volatile int* a = NULL){m_a = a;};
		    ~Task(){};
		    void executeTask(){

          cout << "class thread's start "<< endl;

	        // Loop
				  int localCounter = 0;
				  while(localCounter < 3){
				    localCounter++;
				    sleep(2);
				  }

				  cout << "class thread's end "<< endl;
				  *m_a = 1;
		    };
		};

    volatile int in1 = 0;
    cout << "in1 = " << in1 << endl;

    Task task(&in1);
    boost::thread t1 = boost::thread(&Task::executeTask, &task);
    t1.detach();

    int count = 0;
    while(count < 8){
      cout << "in1 = " << in1 << endl;
      sleep(1);
      count++;
    }
    t1.interrupt();

    in1 = 0;
    Task task2(&in1);
    t1 = boost::thread(&Task::executeTask, &task2);
    t1.detach();

    count = 0;
    while(count < 8){
      cout << "in1 = " << in1 << endl;
      sleep(1);
      count++;
    }
    t1.interrupt();

  }

  return 0;
}