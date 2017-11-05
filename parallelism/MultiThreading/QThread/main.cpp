#include "main.hpp"

#ifdef CUDA_FOUND
#include <cuda.h>
#include <cuda_runtime.h>
#endif

#include <iostream>
#include <unistd.h>
#include <QCoreApplication>
#include "MyThread.hpp"

#include <vector>

int main(int argc, char* argv[])
{
  QCoreApplication a(argc, argv);

  MyThread* newThread1 = new MyThread("A");
  newThread1->start();
  std::cout << "nb Perfect Thread " << newThread1->idealThreadCount() << std::endl;

  MyThread newThread2("B");
  newThread2.start();

  std::cout << "newThread1 " << newThread1->isRunning() << std::endl;
  std::cout << "newThread2 " << newThread2.isRunning() << std::endl;

  usleep(30000);

  newThread1->exit();
  newThread2.exit();

  std::cout << "newThread1 " << newThread1->isRunning() << std::endl;
  std::cout << "newThread2 " << newThread2.isRunning() << std::endl;

  delete newThread1;

  return a.exec();
}