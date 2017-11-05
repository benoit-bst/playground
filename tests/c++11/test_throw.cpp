#include <iostream>
#include <stdexcept>
#include <vector>

/*
 * compile : g++ -std=c++11 test_throw.cpp
 * Ne jamais utiliser les catchs dans des applications devant être performantes
 */
int main()
{
  // ----------------------------------------------------
  {
    try{
      throw 20;
    }
    catch (int e){
      std::cerr << "An exception occured " << e << "\n";
    }
  }

   // ----------------------------------------------------
  {

    try{
      std::vector<int> tab(10);
      tab.at(10);
    }
    catch (const std::exception & e){
      std::cerr << e.what() << "\n";
    }
  }

  // ----------------------------------------------------
  {
    try{
      int i = 0;
    }
    catch (const std::bad_alloc &){
      std::cout << "Erreur : Mémoire insuffisante" << "\n";
    }
    catch (const std::out_of_range &){
      std::cout << "Erreur : débordment de mémoire " << "\n";
    }
  }
}