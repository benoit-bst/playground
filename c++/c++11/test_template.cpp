#include <iostream>
#include <complex>
#include <typeinfo>
#include <tuple>
#include <vector>
#include <string>

//*************************************
// Template
template <size_t T>
size_t func1(){return T;}

template <class T>
T func2(T a){return a;}

template <typename T>
T func3(T a){return a;}

//*************************************
// Template variadique
template <typename T>
T adder(T v){
  return v;
}
template <typename T, typename... Args>
T adder(T first, Args... args){
  return first + adder(args...);
}

//*************************************
// Template
template <typename T>
class A
{
public:
  T a;
};

template <>
class A<bool>
{
  unsigned int a;
};

//************************************
// Template sur differents types
class B{
public:
  template <typename T> void func(T & var){std::cout << "template 1 " << var << "\n";};
  template <typename T> void func(std::complex<T> & var){std::cout << "template 2 " << var << "\n";};
};


//--------------------------------------
// test trait with template
//--------------------------------------
struct Traits {

  static constexpr int kikou() {
      return {};
  }

};

class Test1 : public Traits {

public:
  static constexpr int kikou() {
      return 20;
  };
};

class Test2 : public Traits {

public:
  static constexpr int kikou() {
      return 20;
  };
};

template <typename T = Traits>
class TemplateClass {

public:
  TemplateClass() {};
  int var1() {return T::kikou();};

private:
 int _var1;
};

//************************************
// Multi template
template <typename... Args>
void func_to_test_typeid(Args... args) {

    std::tuple<Args...> argsTuple{std::forward<Args>(args)...};
    int val = std::tuple_size<decltype(argsTuple)>::value;

    // std::cout << "size " << val << std::endl; not work because get add a const int
    // for(size_t i = 0; i < val; ++i) {
    //   std::get<i>(argsTuple);
    // }

}

template<unsigned Idx, class ...Args>
using Selector = std::tuple_element<Idx, std::tuple<Args...>>;

template<class... Args>
void foo(Args... args) {
  static_assert(sizeof...(Args) >= 3, "Erreur : au moins 3 arguments attendus");
  using Type1 = typename Selector<0, Args...>::type;
  using Type2 = typename Selector<1, Args...>::type;
  using Type3 = typename Selector<2, Args...>::type;
  // ...
}

/*
 * compile : g++ -std=c++11 test_template.cpp
 * C++11 : Introduction des variadiques templates
 * typename/class : le new c'est typename
 * à cause de l'ambiguité du keyword class.
 */
int main()
{
  std::cout << func1<5>() << std::endl;
  // std::cout << func1<5.5>() << std::endl; error
  std::cout << func2<int>(4) << std::endl;
  std::cout << func3<int>(4) << std::endl;
  std::cout << adder(4) << std::endl;
  std::cout << adder(1,2,3) << std::endl; // !!! Variadic

  A<int> classA;
  std::cout << classA.a << "\n";

  B b1;
  int z1 = 1;
  b1.func(z1);

  B b2;
  float z2 = 1.0f;
  b2.func(z2);

  B b3;
  double z3 = 1.0f;
  b3.func(z3);

  B b4;
  std::complex<int> comp1(1.5,1.5);;
  b4.func(comp1);

  // template with a trait
  TemplateClass<Test1> tC1;
  std::cout << tC1.var1() << std::endl;

  TemplateClass<Test2> tC2;
  std::cout << tC2.var1() << std::endl;

  // test typeid with template
  // func_to_test_typeid<int, float, double>(3, 3.4f, 5.789);
  func_to_test_typeid(3, 3.4f, 5.789);

  foo(1,2,3);
}
