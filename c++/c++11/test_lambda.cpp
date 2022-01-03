#include <iostream>
#include <functional>

// Lambda
// compile : g++ -std=c++11 test_lambda.cpp
int main()
{
  std::cout << "Lambda :" << std::endl << std::endl;
  
  auto func1 = [] { std::cout << "lambda 1" << std::endl; };
  func1();
  
  int i = 99;
  
  auto func2 = [i] () { std::cout << "lambda 2 : " << i << std::endl; };
  func2();
  
  auto func3 = [] (int & i) { std::cout << "lambda 3 : " << i << std::endl; };
  func3(i);
  
  auto func4 = [] (int i) { std::cout << "lambda 4 : " << i << std::endl; };
  func4(i);
  
  std::function<void()> func5 = [=] () { std::cout << "lambda 5 : " << i << std::endl; };
  func5();
  
  auto func6 = [] (int i) -> int { return i; };
  std::cout << "lambda 6 : " << func6(i) << std::endl;
  
  auto func7 = [] (int i) { return i; };
  std::cout << "lambda 7 : " << func7(i) << std::endl;
  
  std::cout << "lambda 8 : " << [] (int i) -> int { return i; } (2) << std::endl;
  
  int func9 = [] (int i, int j) { return i*j; } (2,2);
  std::cout << "lambda 9 : " << func9 << std::endl;
}