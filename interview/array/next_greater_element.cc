/*
For the input array [4, 5, 2, 25], the next greater elements for each element are as follows.
Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1
For the input array [13, 7, 6, 12}, the next greater elements for each element are as follows.

  Element        NGE
   13      -->    -1
   7       -->     12
   6       -->     12
   12      -->     -1
 */
#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(N^2)
// Auxiliary Space: O(1)
void printNGE(int arr[], int n)
{
    int next, i, j;
    for (i = 0; i < n; i++)
    {
        next = -1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << " -- "
             << next << endl;
    }
}

// Time Complexity: O(N)
// Auxiliary Space: O(N)
void stack_printNGE(int arr[], int n)
{
    stack<int> s;
    vector<int> res(n, 0);

    for (int i = n - 1; i >= 0; i--) {
        /* if stack is not empty, then
        pop an element from stack.
        If the popped element is smaller
        than next, then
        a) print the pair
        b) keep popping while elements are
        smaller and stack is not empty */
        if (!s.empty()) {
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " --> " << res[i] << endl;
}

// Without order !!
// time:  O(n*log(n))
// space: O(n)
void pq_printNGE(int arr[], int n)
{
    priority_queue<int,vector<int>,greater<int> > q;

    // fill min heap
    for( int i = 0; i < n; ++i ) {
        q.push(arr[i]);
    }

    vector<int> printer;
    while( !q.empty()) {

        if (printer.size() == 2) {
            for (auto _val : printer) {
                cout << _val << " ";
            }
            cout << endl;
            swap(printer[0], printer[1]);
            printer.resize(1);

        } else {
            printer.push_back(q.top());
            q.pop();

        }
    }
    if (printer.size() == 2) {
        for (auto _val : printer) {
            cout << _val << " ";
        }
        cout << endl;
        cout << printer[1] << " -1";
        printer.clear();

    } else {
        for (auto _val : printer) {
            cout << _val << " -1";
        }
    }
    cout << endl;
}

int main()
{
    {
        int arr[] = {11, 13, 21, 3};
        int n = sizeof(arr)/sizeof(arr[0]);
        printNGE(arr, n);
        // 11 -- 13
        // 13 -- 21
        // 21 -- -1
        // 3 -- -1
        cout << endl;
    }
    {
        int arr[] = {11, 13, 21, 3};
        int n = sizeof(arr)/sizeof(arr[0]);
        stack_printNGE(arr, n);
        // 11 -- 13
        // 13 -- 21
        // 21 -- -1
        // 3 -- -1
        cout << endl;
    }
    {
        int arr[] = {11, 13, 21, 3};
        int n = sizeof(arr)/sizeof(arr[0]);
        pq_printNGE(arr, n);
        // 11 -- 13
        // 13 -- 21
        // 21 -- -1
        // 3 -- -1
        cout << endl;
    }
    {
        int arr[] = {11, 13, 21, 3, 100};
        int n = sizeof(arr)/sizeof(arr[0]);
        pq_printNGE(arr, n);
        // 11 -- 13
        // 13 -- 21
        // 21 -- -1
        // 3 -- -1
    }
    return 0;
}

