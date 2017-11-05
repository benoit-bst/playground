#include <iostream>
#include <utility>
#include <string>

// Norme c++11
// Le move permet de déplacer le rvalue en argument sur un autre rvalue.
// Cela évite les copies d'objet.
// On utilise la pile pour éviter la copie dans une zone mémoire (fast)

//compile : g++ -std=c++11 test_move.cpp
int main()
{
  std::string str = "test";
  std::cout << "avant move str  : " << str << std::endl;
  std::string str2 = std::move(str);
  std::cout << "apres move str  : " << str  << " devient une valeur vide... :-)" << std::endl;
  std::cout << "apres move str2 : " << str2 << std::endl;

}
