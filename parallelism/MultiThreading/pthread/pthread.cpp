#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#include <iostream>

void* task(void* argument)
{
  char* msg;
  msg = (char*)argument;
  std::cout << msg;
}

/**
 * g++ -lpthread pthread.cpp
 */
int main(int argc, char const *argv[])
{
  pthread_t thread1, thread2;

  int i1, i2;
  i1 = pthread_create(& thread1, NULL, task, (void*)"thread1\n");
  i2 = pthread_create(& thread2, NULL, task, (void*)"thread2\n");

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  return 0;
}