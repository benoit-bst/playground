#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

#include <fcntl.h>

/**
 * g++ openpipetest.cpp
 *
 */
int main(int argc, char const *argv[])
{
  int fd;
  if (fd == open("canal", O_WRONLY|O_NONBLOCK) < 0)
    fprintf(stderr, "open fifo error\n");

  return 0;
}