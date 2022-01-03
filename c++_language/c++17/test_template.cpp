#include <iostream>

/*
 * compile : g++-7 -std=c++17 test_template.cpp
 */

template <auto value> constexpr auto contant = value;
template <auto value> void f() { /* ... */ };
template <auto value> struct B { /* ... */ };

template<std::size_t SIZE>
class Foo {}; 

template <template<auto> class T, auto K>
auto extractSize(const T<K>&) {
    return K;
}

int main()
{
  // Constexpr
  constexpr auto const ConstInt42 = contant<45>;
  std::cout << "val : " << ConstInt42 << std::endl;
  
  // function
  f<10>();         // deduces int
  f<'a'>();        // deduces char
  //f<1.2>();      // error: template parameter type cannot be double

  // Struct
  B<5> b1;         // OK: template parameter type is int
  B<'a'> b2;       // OK: template parameter type is char
  //B<2.5> b3;     // error: template parameter type cannot be double

  // template of template
  {
    Foo<6> f1;
    Foo<'a'> f2;
    std::cout << extractSize(f1) << std::endl;
    std::cout << extractSize(f2) << std::endl;
  }

  return 0;
}
