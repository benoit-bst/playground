#include <iostream>
#include <fstream>

#include <boost/signals.hpp>

using namespace std;

float print_sum(float x, float y){
  return x+y;
}
float print_product(float x, float y){
  return x*y;
}

/**
 * compile : g++ -lboost_signals signals.cpp
 */
int main(int argc, char const *argv[])
{
  {
    boost::signal<float (float, float)> sig;

    sig.connect(1, &print_sum);
    sig.connect(0, &print_product);

    std::cout << sig(5, 3) << std::endl;

    sig.disconnect(&print_sum);
  }

  {
    boost::signal<float (float, float)> sig;
    boost::signals::connection c = sig.connect(&print_sum);

    c.block();
    c.unblock();

    if (c.connected()){
      std::cout << sig(5, 3) << std::endl;
    }

    c.disconnect(); // All slot
  }

  return 0;
}