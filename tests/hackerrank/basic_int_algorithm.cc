#include<cmath>
#include<bitset>

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
    // digit sum
    //*********************************
    {
        auto digit_sum = [](long long input) {
            int sum = 0;

            input = abs(input);

            while (input > 0) {
                sum += input % 10;
                input /= 10;
            }
            return sum;
        };
        int input = 123;
        cout << "digit sum: " << digit_sum(input) << endl; // 6
        input = 2;
        cout << "digit sum: " << digit_sum(input) << endl; // 2
        input = 55554;
        cout << "digit sum: " << digit_sum(input) << endl; // 24
        input = -55554;
        cout << "digit sum: " << digit_sum(input) << endl; // 24
    }

    //*********************************
    // digit reverse
    //*********************************
    {
        auto digit_reverse = [](long long input) {
            int rev = 0;

            input = abs(input);

            while (input > 0) {
                rev = rev * 10 + input % 10;
                input /= 10;
            }
            return rev;
        };

        int input = 123;
        cout << "digit sum: " << digit_reverse(input) << endl; // 321
        input = 2;
        cout << "digit sum: " << digit_reverse(input) << endl; // 2
        input = 55554;
        cout << "digit sum: " << digit_reverse(input) << endl; // 45555
        input = -55554;
        cout << "digit sum: " << digit_reverse(input) << endl; // 45555
    }

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
    // set bit
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

    //*********************************
    // if int is even and odd
    //*********************************
    {
        int n = 3;
        if (n & 1) {
            cout << "is odd" << endl;
        } else {
            cout << "is even" << endl;
        }
    }

    //*********************************
    // have opposite sign
    //*********************************
    {
        int x = 2;
        int y = -3;
        bool isOpposite = ((x ^ y) < 0);
    }

    //*********************************
    // swap 2 numbers
    //*********************************
    {
        int x = 2;
        int y = 4;

        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }

    //*********************************
    // number to binary string
    //*********************************
    {
        cout << bitset<8>(123) << endl;
        string str = bitset<8>(123).to_string();
    }
    //*********************************
    // binary string to number
    //*********************************
    {
        cout << bitset<8>("11011011").to_ulong() << endl;
    }
    //*********************************
    // char to int
    //*********************************
    {
        char a = '1';
        int i = a - '0';
        cout << i << endl;
    }

    return 0;
}
