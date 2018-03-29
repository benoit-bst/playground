#include <iostream>
#include <string>
#include <optional>

using namespace std;

/*
 * compile : g++-7 -std=c++17 test_optionnal.cpp
 *
 */
class A {
    int a;
    int b;
};

class B {
    int a;
    std::optional<int> b;
};

// std::nullopt can be used to create any (empty) std::optional
auto create(bool b) {
    return b ? std::optional<std::string>{"Godzilla"} : std::nullopt; // can be replace by {}
}

int main()
{

   // test optional size
    A a;
    B b;
    cout << "sizeof A      : " << sizeof(A) << endl; // 8
    cout << "sizeof B      : " << sizeof(B) << endl; // 12
    if (auto str = create(false)) {
        cout << "res : " << *str << endl;
    }
    if (auto str = create(true)) {
        cout << "res : " << *str << endl;
    }
    cout << "res : " << create(false).value_or("empty") << endl;

    

    return 0;
}