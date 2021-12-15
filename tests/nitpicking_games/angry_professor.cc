/*
Angry Professor
The main logic of the Angry Professor is :

To count the number of arrivalTime which is less than 1.
Check count is greater than or equal to k and return accordingly.
The time complexity for this is (n). Where n is the size of the array.

This is the main logic of the solution for Angry Professor in C++. Please dry and run the code for a better understanding.
*/
#include <bits/stdc++.h>

using namespace std;

string angryProfessor(int k, vector<int> a) {
    int len = a.size();
    int count =0;
    for(int i=0; i<len; i++)
    {
        if(a[i]<1)
        {
          count++;
        }
    }
    if(count>=k)
    {
        return "NO";
    }
    else
    {
        return "YES";
    }
}

int main()
{
    int k = 3;
    vector<int> a = {1, 2, 3};
    cout << angryProfessor(k, a) << endl; // YES

    k = 3;
    a = {-1, -2, -3};
    cout << angryProfessor(k, a) << endl; // NO

    k = 2;
    a = {-1, -1, 1};
    cout << angryProfessor(k, a) << endl; // NO

    return 0;
}

