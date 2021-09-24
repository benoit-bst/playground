#include<cmath>
#include <bits/stdc++.h>

using namespace std;

int main() {

    //*********************************
    // count digit number
    //*********************************
    int x = 999;
    int numberOfDigits = x > 9 ? static_cast<int>(log10(x) + 1) : 1;
    cout << "val " << numberOfDigits << endl;

    //*********************************
    // is divisible by
    //*********************************
    int div = 3;
    if (x % div == 0) {
        cout << "is divisible" << endl;
    }

    //*********************************
    // shift
    //*********************************
    int a = 4;
    a = a << 1;
    cout << "shift " << a << endl; // 8
    a >>= 1;
    cout << "shift " << a << endl; // 4

    //*********************************
    // get bit
    //*********************************
    auto getbit = [](int num, int i) {
        return ((num & (1 << i)) != 0);
    };
    cout << "get bit " << getbit(4, 2) << endl; // true

    //*********************************
    // get bit
    //*********************************
    auto setbit = [](int num, int i) {
        return num | (1 << i);
    };
    cout << "set bit " << setbit(4, 1) << endl; // 6

    //*********************************
    // clear bit
    //*********************************
    auto clearbit = [](int num, int i) {
        int mask = ~(1 << i);
        return num & mask;
    };
    cout << "clear bit " << clearbit(4, 2) << endl; // 0

    //*********************************
    // update bit
    //*********************************
    auto updatebit = [](int num, int i, bool bits1) {
        int value = bits1 ? 1 : 0;
        int mask = ~(1 << i);
        return (num & mask) | (value << i);
    };
    cout << "update bit " << updatebit(4, 3, true) << endl; // 12
    cout << "update bit " << updatebit(4, 2, false) << endl; // 0



    return 0;
}
