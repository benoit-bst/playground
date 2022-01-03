#include <iostream>

using namespace std;

/*
 * compile : g++ -std=c++11 test_pointeur.cpp
 */
int main()
{
  // Pointeur
  {
    // pointeur sur int
    int* a = new int(10);
    cout << "adress : " << &a << " - val : " << *a << " - ptr : " << a << endl;
    delete a;


    int* b = new (nothrow) int[10];
    *b = 0;
    cout << "adress : " << &b << " - val : " << *b << " - ptr : " << b << endl;
    // *++b = 1; // Si le ptr bouge alors le delete [] ne marche plus avec b[] c'est okay
    b[1] = 1;
    cout << "adress : " << &b << " - val : " << *b << " - ptr : " << b << endl;
    delete[] b;

  }

  return 0;
}