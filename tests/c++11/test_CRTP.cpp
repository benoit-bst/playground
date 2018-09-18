/**
 * g++ -std=c++11 test_CRTP.cpp
 */

#include <iostream>

using namespace std;

template<class T>
class Base
{
public:
    void interface()
    {
        static_cast<T*>(this)->implem();
    }

};
class Derived : public Base<Derived>
{
public:
    void implem()
    {
        cout << "Derived implem" << endl;
    }

};

int main()
{
    Derived d;
    d.interface(); // print Derived implem

    return 0;
}
