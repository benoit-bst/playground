#include <iostream>
#include <memory>
#include <vector>
#include <type_traits>

// Lambda
// compile : g++ -std=c++11 test_rvalue.cpp

template <typename T>
void bazinga(T&& t){
  
}

int returnRef(){int x= 1;return x;};

float f(){}

std::unique_ptr<int> make_int_unique(int i) 
{
  return std::unique_ptr<int>(new int(i));
}

template<typename T, typename P1>
std::shared_ptr<T> factory(P1 &&p1) 
{
  return std::shared_ptr<T>(new T(std::forward<P1>(p1)));
}

/*
 * Le concept lvalue/rvalue s'applique au expression.
 * 
 * 
 * lvalue : Est une expression dont l'adresse peut être récupéré. Un lvalue persiste en mémoire.
 *          On peut donc assigner sur un lvalue.
 *          On peut donc récupérer l'ad (&) d'une lvalue. Pas pour le rvalue.
 * rvalue : N'est pas un lvalue. C'est quelque chose qui n'a pas de nom et qui ne persiste qu'au travers d'une expression.
 *          Une expression est un rvalue si le résultats est un objet temporaire.*
 *          Les Rvalues-references peuvent recevoir seulement des lvalue constant (Problème du perfect forwarding)
 *
 * Les rvalue permettent le move semantic et le perfect forwarding
 * - Move semantic : permettant d'optimiser les copîes couteuses et inutiles en subtilisant les ressources
 * - perfect forwarding : Permet de transferer des arguments entre deux fonctions templates tout en conservant leur propriété const-ness et value-ness
 */
int main()
{
  // int is a lvalue
  // 5 is a rvalue
  std::cout << std::boolalpha;
  std::cout << std::is_rvalue_reference<int>::value << std::endl;
  std::cout << std::is_rvalue_reference<int&&>::value << std::endl;

  bazinga(4);      // 4 is a rvalue -> T deducted to int

  double d = 3.14;
  bazinga(d);      // d is a lvalue -> T deduced to double&

  const double da = 3.14;
  bazinga(da);     // d is a lvalue -> T deduced to double&

  bazinga(f());    // f() is rvalue -> T deduced to float


  std::vector<std::unique_ptr<int>> vec;
  vec.push_back(std::unique_ptr<int>(new int(40))); // OK
  vec.push_back(make_int_unique(2)); // OK

  std::unique_ptr<int> i1(new int(21));
  //vec.push_back(i1); // KO : i1 n'est pas copiable
  vec.push_back(std::move(i1)); // OK

  //-------------------------
  // Perfect forwarding
  // Permet la non surcharge de plusieurs fonction
  // a cause des paramètres d'entrée en 
  // ref - non-ref - const-ref - etc
  // && & = &
  // & && = &
  // & &  = &
  //-------------------------
  int a = 3;
  const int b = 6;
  int & bRef = a;
  std::shared_ptr<int> p1 = factory<int>(a);
  std::shared_ptr<int> p2 = factory<int>(b);
  std::shared_ptr<int> p3 = factory<int>(5);
  std::shared_ptr<int> p5 = factory<int>(bRef);

  class A {
  public:
    A(std::string &str) { }
  };
  std::string hello("Hello");
  std::shared_ptr<A> p4 = factory<A>(hello);
}