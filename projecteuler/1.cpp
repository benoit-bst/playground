/*
 * https://projecteuler.net/problem=1
 *
 * compil : g++ -std=c++11 1.cpp
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    size_t sum = 0;
    for(size_t i = 0; i < 1000; ++i) {
        if ((i % 3 == 0) || (i % 5 == 0)) {
            sum += i;
        }
    }
    cout << "result : " << sum << endl; // 233168

    return 0;
}
