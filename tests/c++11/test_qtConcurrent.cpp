#include <iostream>
#include <qtconcurrentmap.h>
#include <vector>



void function(std::vector<int> & in, std::vector<int> & out){
  for (int i = 0; i < in.size(); ++i){
    out[i] = in[i] + 1;
  }
}

int main()
{
  std::cout << "Test QtConcurrent" << std::endl;
  
  // Creation du signal
  std::vector<int> a;
  for (int i = 0; i < 100000000; ++i){
  a.push_back(1);
  }
  
  
  
  
//   QtConcurrent::blockingMap( codeCarriers, demod_and_decod_carrier );
  
  return 0;
}