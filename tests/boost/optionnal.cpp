#include <iostream>
#include <fstream>
#include <vector>

#include <boost/optional.hpp>

using namespace std;

boost::optional<int> convert(const std::string& text);

/**
 * compile : g++ optionnal.cpp
 */
int main(int argc, char const *argv[])
{
  {
  	boost::optional<int> opt_int(3);
  	if (opt_int){
  	  std::cout << "opt_int initialise " << *opt_int << "\n";
  	}
  	opt_int = boost::none;
  	if (!opt_int){
      std::cout << "opt_int no initialise " << "\n";
    }
  }

  return 0;
}