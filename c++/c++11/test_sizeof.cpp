#include <iostream>

using namespace std;


class BaseStatic
{
  int a;
  static int b;
};
int BaseStatic::b;


/*
 * compile : g++ -std=c++11 test_sizeof.cpp
 */
int main()
{
  {
  	class Test1
  	{
  		Test1(){};
      int i;
      int j;
  	};
  	cout << "sizeof Test1 (2*int) : " << sizeof(Test1) << endl; // 2*4 = 8
  	class Test2
  	{
  		Test2(){};
  	};
  	cout << "sizeof Test2         : " << sizeof(Test2) << endl; // 1
  	short* s1;
  	cout << "sizeof short*        : " << sizeof(s1) << endl;    // 8
  	int* i1;
  	cout << "sizeof int*          : " << sizeof(i1) << endl;    // 8
  	double* d1;
  	cout << "sizeof double*       : " << sizeof(d1) << endl;    // 8
  }

  /*
   * Inherance
   */
  {
  	class Base
  	{
      int arrr[10];
  	};
  	class B1 : public Base {};
  	class B2 : public Base {};

  	class Derived : public B1, public B2 {};

    cout << "sizeof Base : " << sizeof(Base) << endl; // 4*10 = 40
  	cout << "sizeof Derived : " << sizeof(Derived) << endl; // 4*10*2 = 80
  	cout << "sizeof B1      : " << sizeof(B1) << endl;      // 40
  }

  /*
   * virtual
   */
  {
  	class Base
  	{
      int arrr[10];
  	};
  	class B1 : virtual public Base {};
  	class B2 : virtual public Base {};

  	class Derived : public B1, public B2 {};

    cout << "sizeof Base : " << sizeof(Base) << endl; // 4*10 = 40
  	cout << "sizeof Derived : " << sizeof(Derived) << endl;  // 56
  	cout << "4*10 + 8 + 8" << endl;
    cout << "sizeof B1 : " << sizeof(B1) << endl;            // 48
  }

  /*
   * virtual
   */
  {
  	class Base
  	{
      int x;
    public:
      virtual void show() {}
  	};
  	cout << "sizeof Base : " << sizeof(Base) << endl;  // ( int=4 + paddingInt=4 + Virtfunct=8 )= 16

  	class Base2
  	{
      int x;     // 4
      double c;  // 8
  	};
  	cout << "sizeof Base : " << sizeof(Base2) << endl;  // ( int=4 + paddingInt=4 + double=8 )= 16

    class Base3
    {
      double c;  // 8
      int x;     // 4
    };
    cout << "sizeof Base : " << sizeof(Base3) << endl;  // ( int=4 + paddingInt=4 + double=8 )= 16
  }

  /*
   * virtual
   * La VTable contient le pointeur de chaque objet/Fonction virtuelle
   * Donc pour chaque element virtuel on obtient la size d'un pointeur soit 8
   */
  {
  	class Base
  	{
      int arrr[10];
      virtual void funcA();
  	};

  	cout << "sizeof Derived : " << sizeof(Base) << endl;  // 48 = 4*10 + 8
  }

  /*
   * static
   * Static ne contribue pas à la taille de l'objet et les fonctions static aussi
   */
  {


    cout << "sizeof static : " << sizeof(BaseStatic) << endl;  // = 4 la taille d'un int (a)
  }

  /*
   * tests size foa class with function
   */
  {
    class Base
    {
      float a;
      void funcA();
      void funcB(int b);
    };

    cout << "sizeof Base : " << sizeof(Base) << endl;  // 48 = 4*10 + 8
  }

  /*
   * ordering class
   */
  {
    class Base
    {
      int a;
      int* prt;
    };

    cout << "sizeof Base : " << sizeof(Base) << endl;  // 16 = 4 + padding(4) + 8
  }

  /*
   * ordering class
   */
  {
    class Base
    {
      int* prt;
      int a;
    };

    cout << "sizeof Base : " << sizeof(Base) << endl;  // 16 = 8 + padding(4) + 4
  }

  return 0;

}
