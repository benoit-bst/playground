#include <iostream>

#include <cstdlib>
#include <cassert>
#include <vector>
#include <functional>

#define NDEBUG //si c'est mis, alors on ne fait pas les assert

double f(double a, double b){return a/b;};

int x = 10;
int y = 10;
void fun()
{
  int x = 2;
  int y = 2;
  {
    int x = 1;
    int y = 1;
    std::cout << "::x " << ::x << std::endl;
    std::cout << "y   " << y << std::endl;
  }
}

// compile : g++ -std=c++11 test_function.cpp
int main()
{
  // Bind
  using namespace std::placeholders; // permet l'utilisation des _1, _2

  auto f1 = std::bind(f,_1, 2);
  std::cout << "bind f1 :" << f1(10) << std::endl;

  struct Foo{
    void print_sum(int a, int b){
      std::cout << "Foo Somme : "<< a+b << std::endl;
    }
  };
  Foo foo;
  auto f2 = std::bind(&Foo::print_sum, foo, 100, _1);
  f2(10);

  // Function
  std::function<void()> f3 = []() {std::cout << "lambda "<< std::endl;};
  f3();

  std::function<double(double, double)> f4 = f;
  std::cout << "f4 : "<< f4(10, 2) << std::endl;

  // assert
  std::cout << "assert :" << std::endl;
  assert(2+2 == 4);

  {
    fun();
  }

  // reference_wrapper
  // permet d'utiliser les références dans les conteneurs de la STL
  // Sinon il y a copy et non ref
  {
    int a = 1;
    int b = 2;
    int c = 3;
    std::vector<std::reference_wrapper<int>> vec={std::ref(a), std::ref(b), std::ref(c)};
    c = 4; //donc vec[2] = 4
  }

  // abort
  std::cout << "abort :" << std::endl;
  std::abort(); // Abort
}
