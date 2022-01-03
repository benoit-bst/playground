#include <iostream>
#include <regex>
#include <string>
#include <stdexcept>

using namespace std;

// compile : g++ -std=c++11 regexC++11.cpp
int main()
{
  /**
   * Match with regex
   */
  {
    string s = "couCoucou toi\n";
    regex r1("(.*)Cou(.*)");
    regex r2("(.*)Tata(.*)");
    regex r3("couCoucou toi\n");

    std::cout << "Match Cou  : " << regex_match(s, r1) << std::endl;
    std::cout << "Match Tata : " << regex_match(s, r2) << std::endl;
    std::cout << "Match same : " << regex_match(s, r3) << std::endl;
  }

  /**
   * Search with regex
   */
  {
    // string s = "I am looking for something\n";
    // regex r("(for)([a-z])");
    // smatch m;

    // std::cout << "Search for  : " << regex_search(s, m, r) << std::endl;
  }

  /**
   * Replace with regex
   */
  {
    string s = "Coucou toi\n";
    regex r("Coucou toi\n");
    string val = "geek";

    regex_replace(s, r, val);
    std::cout << "Replace : " << s << std::endl;
  }

  return 0;
}