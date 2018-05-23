/*
 * https://projecteuler.net/problem=2
 *
 * compil : g++ -std=c++11 2.cpp
 */
#include <iostream>

using namespace std;

int main()
{
    // my solution
    {
        uint64_t sum = 0, tmp = 0;
        uint64_t first = 1;
        uint64_t second = 2;
        uint64_t limit = 4000000;

        while (first <= limit) {

            // even-valued terms
            if (first % 2 == 0) {
                sum += first;
            }

            tmp = first + second;
            first = second;
            second = tmp;
        }

        cout << "result : " << sum << endl; //
    }

    return 0;
}
