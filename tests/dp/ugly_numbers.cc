#include <iostream>
#include <set>

using namespace std;

// This function divides a by greatest
// divisible power of b
int maxDivide(int a, int b)
{
    while (a % b == 0)
        a = a / b;

    return a;
}

// Function to check if a number is ugly or not
int isUgly(int no)
{
    no = maxDivide(no, 2);
    no = maxDivide(no, 3);
    no = maxDivide(no, 5);

    return (no == 1) ? 1 : 0;
}

// Function to get the nth ugly number
int getNthUglyNo(int n)
{
    int i = 1;

    // Ugly number count
    int count = 1;

    // Check for all integers untill ugly
    // count becomes n
    while (n > count)
    {
        i++;
        if (isUgly(i))
            count++;
    }
    return i;
}

// Time Complexity: O(n)
// Auxiliary Space: O(n)
unsigned dp_getNthUglyNo(unsigned n)
{
    // To store ugly numbers
    unsigned ugly[n];
    unsigned i2 = 0, i3 = 0, i5 = 0;
    unsigned next_multiple_of_2 = 2;
    unsigned next_multiple_of_3 = 3;
    unsigned next_multiple_of_5 = 5;
    unsigned next_ugly_no = 1;

    ugly[0] = 1;
    for (int i = 1; i < n; i++) {
        next_ugly_no = min(
            next_multiple_of_2,
            min(next_multiple_of_3, next_multiple_of_5));
        ugly[i] = next_ugly_no;
        if (next_ugly_no == next_multiple_of_2) {
            i2 = i2 + 1;
            next_multiple_of_2 = ugly[i2] * 2;
        }
        if (next_ugly_no == next_multiple_of_3) {
            i3 = i3 + 1;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        if (next_ugly_no == next_multiple_of_5) {
            i5 = i5 + 1;
            next_multiple_of_5 = ugly[i5] * 5;
        }
    }

    // End of for loop (i=1; i<n; i++)
    return next_ugly_no;
}

// Time Complexity:- O(N log N)
// Auxiliary Space:- O(N)
int set_nthUglyNumber(int n)
{
    // Base cases...
    if (n == 1 or n == 2 or n == 3 or n == 4 or n == 5)
        return n;

    set<long long int> s;
    s.insert(1);
    n--;

    while (n) {
        auto it = s.begin();

        // Get the beginning element of the set
        long long int x = *it;

        // Deleting the ith element
        s.erase(it);

        // Inserting all the other options
        s.insert(x * 2);
        s.insert(x * 3);
        s.insert(x * 5);
        n--;
    }

    // The top of the set represents the nth ugly number
    return *s.begin();
}

// Driver Code
int main()
{
    // Function call
    unsigned no = getNthUglyNo(150);
    cout << "150th ugly no. is " << no << endl;
    no = dp_getNthUglyNo(150);
    cout << "150th ugly no. is " << no << endl;
    no = set_nthUglyNumber(150);
    cout << "150th ugly no. is " << no << endl;

    return 0;
}
