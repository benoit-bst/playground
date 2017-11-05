#include <iostream>

int main(int argc, char const *argv[])
{

#if TOTO
  std::cout << "define" << std::endl;
#else
  std::cout << "Not define" << std::endl;

#endif

  return 0;
}