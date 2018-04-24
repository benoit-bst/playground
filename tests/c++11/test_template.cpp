#include <iostream>
#include <complex>

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
}
