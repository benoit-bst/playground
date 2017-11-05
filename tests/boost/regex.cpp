#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <iterator>

#include <boost/regex.hpp>
#include <boost/xpressive/xpressive.hpp>

using namespace std;
using namespace boost;

static const boost::regex expression("(\\d{4}[- ]){3}\\d{4}");
static const boost::regex separate_chunks("ONE|TWO");

/**
 * compile : g++ -lboost_regex regex.cpp
 */
int main(int argc, char const *argv[])
{
  // Regex
  {
    std::string card = "0000 1111 2222 3333";
    bool valid = boost::regex_match(card, expression);
    std::cout << "check : " << valid << std::endl;

    card = "0000-1111-2222-3333";
    valid = boost::regex_match(card, expression);
    std::cout << "check : " << valid << std::endl;

    card = "0000111122223333";
    valid = boost::regex_match(card, expression);
    std::cout << "check : " << valid << std::endl;
  }

  // Split
  {
    std::string card = "0000 ONE 1111 TWO  2222 3333";
    std::vector<string> l;

    boost::regex_split(std::back_inserter(l), card, separate_chunks);
    for (int i = 0; i < l.size(); ++i)
    {
      std::cout << "split : " << l[i] << std::endl;
    }

  }

  // Replace
  {
    std::string input = "helloooooo";
    std::string newText = "o";
    boost::regex re("oooooo");

    std::string result = boost::regex_replace(input, re, newText);
    std::cout << "replace : " << result << std::endl;
  }




  return 0;
}