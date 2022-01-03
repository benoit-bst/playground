#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <iostream>

#define DEPTH 4

void printChild(int n){
  int a = 0;
  while(a < 10){
    a++;
    std::cout << "child " << n << " - counter " << a << std::endl;
    sleep(1);
  }
  kill(getpid(), SIGKILL);
}

/**
 * g++ forktest.cpp
 *
 * check process id : ps -e | grep a.out
 */
int main(int argc, char const *argv[])
{
  pid_t pid;
  int i;

  std::cout << "My process id = " << getpid() << std::endl;

  for (int i = 0; i < DEPTH; ++i)
  {
     pid = fork(); // Fork

    // if (pid){
    //   break; // Don't give the parent a chance to fork again
    // }
    if (pid == -1){
      std::cout << "Error create fork" << std::endl;
    }
    if (pid == 0){
      std::cout << "Child #" << getpid() << std::endl;
      printChild(i);
    }

  }

  wait(NULL); // Don't let a parent ending first end the tree below

  std::cout << "Barrier" << std::endl;

  return 0;
}