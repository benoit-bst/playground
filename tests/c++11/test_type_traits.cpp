#include <iostream>
#include <type_traits>
#include <vector>

namespace lol {

// TRAIT is_int
template <typename T>
struct is_int : std::false_type
{
};
template <>
struct is_int<int> : std::true_type
{
};

} // namespace lol

// Vector
// compile : g++ -std=c++11 test_type_traits.cpp
int main()
{
  // is_trivial : permet de voir  si le type est trivialement copiable et traivialment constructible par default,
  class A
  {
    A();
  };

  class B
  {
  };

  class C
  {
    int a;
    char *p;
  };

  std::cout << std::boolalpha; // permet l'affichage de 0 a false
  std::cout << "is_trivial A    : " << std::is_trivial<A>::value << std::endl;       // false
  std::cout << "is_trivial B    : " << std::is_trivial<B>::value << std::endl;       // true
  std::cout << "is_trivial C    : " << std::is_trivial<C>::value << std::endl;       // true

  std::cout << "is_trivial int  : " << std::is_trivial<int>::value << std::endl;  // True
  std::cout << "is_trivial char : " << std::is_trivial<char>::value << std::endl; // True

  // POD (Plain Old Data) signifie une classe (struct - class) sans constructeurs, sans destructeurs, et sans fonctions virtuelles
  std::cout << "is_pod A    : " << std::is_pod<A>::value << std::endl;    // False
  std::cout << "is_pod B    : " << std::is_pod<B>::value << std::endl;    // True
  std::cout << "is_pod C    : " << std::is_pod<C>::value << std::endl;    // True

  std::cout << "is_pod int  : " << std::is_pod<int>::value << std::endl;  // True
  std::cout << "is_pod char : " << std::is_pod<char>::value << std::endl; // True

  // Specialization
  // Usefull for trait
  {
    std::cout << "lol::is_int<int>::value : " << lol::is_int<int>::value << std::endl;
  }
}
