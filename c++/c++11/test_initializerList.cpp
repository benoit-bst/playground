#include <iostream>
#include <algorithm>
#include <cstddef>
#include <cassert>

/*
 * Est utile dans le cas :
 * - pour éviter un appel inutile de constructeur quand un classe est maenbre d'une classe
 * - Initialiser les références
 * - Les variables du même nom en entré
 * - Les variables constantes
 * - Pour des questions de performances
 * - Initialisation d'une classe qui n'a pas de constructeur pas default
 */
class APrime
{
  int m_val;
  public:
   APrime(int val){m_val = val;};
};

class A
{
  public:
    A(int a, int & b);
  private:
    int a;
    int & refA;
    const int constA;
    APrime aClass;
};
A::A(int a, int & b)
  :a(a),
  refA(b),
  constA(a),
  aClass(a)
{}

// compile : g++ -std=c++11 test_initializerList.cpp
int main()
{
	{
    int x = 10;
    A a(10, x);
	}

}