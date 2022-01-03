#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <ctime>

int roll_die(){
  boost::random::mt19937 gen(std::time(0));
  boost::random::uniform_int_distribution<> dist(1, 6);
  return dist(gen);
}

int main(int argc, char const *argv[])
{
  std::cout << "Random :" << roll_die() << std::endl;
  return 0;
}