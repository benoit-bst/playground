#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

/**
 * g++ createpipetest.cpp
 *
 */
int main(int argc, char const *argv[])
{

  if (mkfifo("canal", 0664) < 0)
  	fprintf(stderr, "mkfifo error\n");

  return 0;
}