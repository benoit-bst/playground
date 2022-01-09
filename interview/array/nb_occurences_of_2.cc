#include <bits/stdc++.h>

using namespace std;

// Counts the number of '2'
// digits in a single number
int number0f2s(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (n % 10 == 2)
            count++;

        n = n / 10;
    }
    return count;
}

// time: O(N*nb_digit)
// space: O(1)
int numberOf2sinRange(int n)
{
    // Initialize result
    int count = 0 ;

    // Count 2's in every number
    // from 2 to n
    for (int i = 2; i <= n; i++)
        count += number0f2s(i);

    return count;
}


int count2sinRangeAtDigit(int number, int d)
{
    int powerOf10 = (int)pow(10, d);
    int nextPowerOf10 = powerOf10 * 10;
    int right = number % powerOf10;

    int roundDown = number - number % nextPowerOf10;
    int roundup = roundDown + nextPowerOf10;

    int digit = (number / powerOf10) % 10;

    // if the digit in spot digit is
    if (digit < 2)
        return roundDown / 10;

    if (digit == 2)
        return roundDown / 10 + right + 1;

    return roundup / 10;
}

// Counts the number of '2' digits between 0 and n
int op_numberOf2sinRange(int number)
{
    // Convert integer to String
    // to find its length
    stringstream convert;
    convert << number;
    string s = convert.str();
    int len = s.length();

    // Traverse every digit and
    // count for every digit
    int count = 0;
    for (int digit = 0; digit < len; digit++)
        count += count2sinRangeAtDigit(number, digit);

    return count;
}

int main()
{
    cout << numberOf2sinRange(22); // 6 -> (2, 12, 20, 21, 22);
    cout << op_numberOf2sinRange(22); // 6 -> (2, 12, 20, 21, 22);
    cout << endl;
    cout << numberOf2sinRange(100); // 20 -> (2, 12, 20, 21, 22..29, 32, 42, 52, 62, 72, 82, 92)
    cout << op_numberOf2sinRange(100); // 20 -> (2, 12, 20, 21, 22..29, 32, 42, 52, 62, 72, 82, 92)

    return 0;
}
