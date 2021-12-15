#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
A Kaprekar number is a number whose square when divided into two parts and such that sum of parts is equal to the original number and none of the parts has value 0. (Source : Wiki)
Given a number, the task is to check if it is Kaprekar number or not.
Examples:


Input :  n = 45
Output : Yes
Explanation : 452 = 2025 and 20 + 25 is 45

Input : n = 13
Output : No
Explanation : 132 = 169. Neither 16 + 9 nor 1 + 69 is equal to 13
*/
bool kaprekar(long long x) {
	// Corner cases for numbers that have a single digit when squared
	if(x == 0) {
		return true;
	}
	if(x == 1) {
		return true;
	}
	if(x == 2) {
		return false;
	}
	if(x == 3) {
		return false;
	}

	long long x_squared = x*x;
	string x_squared_string = to_string(x*x);

    string part1, part2;
	for(long long i = 0; i < x_squared_string.length()/2; i++) {
		part1 += x_squared_string[i];
	}
	for(long long i = x_squared_string.length()/2; i < x_squared_string.length(); i++) {
		part2 += x_squared_string[i];
	}
	if(stoll(part1) + stoll(part2) == x) {
		return true;
	} else {
		return false;
	}
}

// Returns true if n is a Kaprekar number, else false
bool iskaprekar(int n)
{
    if (n == 1)
    return true;

    // Count number of digits in square
    int sq_n = n * n;
    int count_digits = 0;
    while (sq_n)
    {
        count_digits++;
        sq_n /= 10;
    }

    sq_n = n*n; // Recompute square as it was changed

    // Split the square at different poitns and see if sum
    // of any pair of splitted numbers is equal to n.
    for (int r_digits=1; r_digits<count_digits; r_digits++)
    {
        int eq_parts = pow(10, r_digits);

        // To avoid numbers like 10, 100, 1000 (These are not
        // Karprekar numbers
        if (eq_parts == n)
            continue;

        // Find sum of current parts and compare with n
        int sum = sq_n/eq_parts + sq_n % eq_parts;
        if (sum == n)
        return true;
    }

    // compare with original number
    return false;
}

int main() {
    long long p, q;
    cin>>p>>q;

    for(long long i = p; i < q; i++) {
    	if(iskaprekar(i)) {
    		cout<<i<<" ";
    	}
    }
    cout << endl; // from 1 to 100 -> 1 9 45 55 99

    return 0;
}
