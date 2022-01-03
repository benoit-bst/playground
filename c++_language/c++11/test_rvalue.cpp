#include <iostream>
#include <memory>
#include <vector>
#include <type_traits>

// Lambda
// compile : g++ -std=c++11 test_rvalue.cpp

template <typename T>
void bazinga(T&& t){

}

class Copyable
{
public:
  Copyable() : _var(4) {};

  Copyable(Copyable &&) = default;
  Copyable &operator=(Copyable &&) = default;

  Copyable(const Copyable &) = default;
  Copyable &operator=(const Copyable &) = default;
  ~Copyable() {};

  int var() {return _var;};

private:
  int _var;

};

class NonCopyable
{
public:
  NonCopyable() {};

  NonCopyable(NonCopyable &&) = default;
  NonCopyable &operator=(NonCopyable &&) = default;

  NonCopyable(const NonCopyable &) = delete;
  NonCopyable &operator=(const NonCopyable &) = delete;
  ~NonCopyable() {};

};

int returnRef(){int x= 1;return x;};

float f(){}

std::unique_ptr<int> make_int_unique(int i)
{
  return std::unique_ptr<int>(new int(i));
}

/*
 * Perfect forwarding
 */
template<typename T, typename P1>
std::shared_ptr<T> factory(P1 &&p1)
{
  return std::shared_ptr<T>(new T(std::forward<P1>(p1)));
}

template<typename T>
class some_struct
{
    T _v;
public:
    template<typename U>
    some_struct(U&& v)
        : _v(std::forward<U>(v)) // std::forward<U>(v) is a static_cast<U&&>(v)
    {
    }
};

/*
 * rvalue(C++11 concept)/lvalue
 *
 *
 * lvalue : Est une expression dont l'adresse peut être récupéré. Un lvalue persiste en mémoire.
 *          On peut donc assigner sur un lvalue.
 *          On peut donc récupérer l'ad (&) d'une lvalue. Pas pour le rvalue.
 *
 * rvalue : N'est pas un lvalue. C'est quelque chose qui n'a pas de nom et qui ne persiste qu'au travers d'une expression.
 *          Example : x+(y*z); // A C++ expression that produces a temporary
 *          Une expression est un rvalue si le résultats est un objet temporaire.*
 *          Les Rvalues-references peuvent recevoir seulement des lvalue constant (Problème du perfect forwarding)
 *
 * On ne peut pas copier une classe si tous les menbres de cette classe ne sont pas copiables.
 *
 * Les rvalue permettent le move semantic et le perfect forwarding
 * - Move semantic : permettant d'optimiser les copîes couteuses et inutiles en subtilisant les ressources
 * - perfect forwarding : Permet de transferer des arguments entre deux fonctions templates tout en conservant leur propriété const-ness et value-ness
 *
 * std::move is a type casting
 */
int main()
{

  //------------------------------------
  //
  // Declarations
  //
  //------------------------------------

  // rvalue declaration
  // C++11 rvalue reference variable
  std::string&& rvalue_str = "kikou rvalue";

  // lvalue references
  const std::string& lvalue_str_ref = "kikou lvalue ref";

  // lvalue
  std::string lvalue_str = "kikou lvalue";

  //------------------------------------
  //
  // Example with vector
  //
  //------------------------------------
  std::vector<NonCopyable> vect_non_copyable;
  vect_non_copyable.push_back(NonCopyable());         // rvalue
  NonCopyable nc;                                     // lvalue
  //vect_non_copyable.push_back(nc);                  // KO : use of deleted function ‘NonCopyable::NonCopyable(const NonCopyable&)
  vect_non_copyable.push_back(std::move(nc));         // OK we move

  std::vector<Copyable> vect_copyable;
  vect_copyable.push_back(Copyable());                // lvalue (but rvalue with the compiler)
  vect_copyable.push_back(std::move(Copyable()));     // rvalue
  Copyable c;
  vect_copyable.push_back(c);                         // lvalue
  vect_copyable.push_back(std::move(c));              // rvalue

  //------------------------------------
  //
  // rvalue detection
  //
  //------------------------------------
  // int is a lvalue
  std::cout << std::boolalpha;
  std::cout << std::is_rvalue_reference<int>::value << std::endl;
  std::cout << std::is_rvalue_reference<int&&>::value << std::endl;

  //------------------------------------
  //
  // Example with a function
  //
  //------------------------------------

  bazinga(4);              // 4 is a rvalue -> T deducted to int

  double d = 3.14;
  bazinga(d);              // d is a lvalue -> T deduced to double&

  const double da = 3.14;
  bazinga(da);             // d is a lvalue -> T deduced to double&

  bazinga(f());            // f() is rvalue -> T deduced to float

  //------------------------------------
  //
  // Example pointer case
  //
  //------------------------------------

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

  some_struct<int> s1(3);
}
