#include <iostream>

/*
 * compile : g++ -std=c++11 test_auto.cpp
 */

using namespace std;


struct A {

    int a;
    int b;
};

int * func(int * a)
{
    return a;
}

int main( )
{
    // -------------------------
    //
    //
    int *a = new int(10);
    auto* myAuto = func(a);

    cout << a << endl;
    cout << &a << endl;
    cout << *a << endl;

    cout << myAuto << endl;
    cout << &myAuto << endl;
    cout << *myAuto << endl;

    int * b = new int(10);
    int & c = b;
}
