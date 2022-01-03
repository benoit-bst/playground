// C++ program to sort an array in Zig-Zag form
// g++ -std=c++11 array_zigzag_fashion.cpp
#include <iostream>
#include <vector>
using namespace std;

// Program for zig-zag conversion of array
// time complexity : O(N)
// space complexity : O(1)
void zigZag(vector<int>& unsorted_vec)
{
    // Flag true indicates relation "<" is expected,
    // else ">" is expected. The first expected relation
    // is "<" w
    bool flag = true;

    for (int i=0; i < unsorted_vec.size() - 1; ++i)
    {
        if (flag) /* "<" relation expected */
        {
            /* If we have a situation like A > B > C,
            we get A > B < C by swapping B and C */
            if (unsorted_vec[i] > unsorted_vec[i+1])
                swap(unsorted_vec[i], unsorted_vec[i+1]);
        }
        else /* ">" relation expected */
        {
            /* If we have a situation like A < B < C,
            we get A < C > B by swapping B and C */
            if (unsorted_vec[i] < unsorted_vec[i+1])
                swap(unsorted_vec[i], unsorted_vec[i+1]);
        }
        flag = !flag; /* flip flag */
    }
}

// Driver program
int main()
{
    vector<int> unsorted_vec = {4, 3, 7, 8, 6, 2, 1};

    for (int i=0; i < unsorted_vec.size(); ++i)
        cout << unsorted_vec[i] << " ";
    cout << endl;

    zigZag(unsorted_vec);

    for (int i=0; i < unsorted_vec.size(); ++i)
        cout << unsorted_vec[i] << " ";
    cout << endl;

    return 0;
}
