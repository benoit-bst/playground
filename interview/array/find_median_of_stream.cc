#include <bits/stdc++.h>

using namespace std;

// 3 5 10 - > 5
// 3 5 6 10 -> 5.5
//
//
// max heap for the max of the first half
// min heap for the min of the second half
//
// if max and min heap size are equal we choose
// the element into the good heap. we do med = (s.top() + g.top())/2.0;
//
// if max and min heap size are different size select
// the good heap


// time:  O(n*log(N)) - > log N for the heap insert
// space: O(N)
void find_stream_median(vector<int>& arr)
{
    // max heap to store the smaller half elements
    priority_queue<double> s;

    // min heap to store the greater half elements
    priority_queue<double,vector<double>,greater<double> > g;

    double med = arr[0];
    s.push(arr[0]);

    cout << med << endl;

    // reading elements of stream one by one
    /*  At any time we try to make heaps balanced and
        their sizes differ by at-most 1. If heaps are
        balanced,then we declare median as average of
        min_heap_right.top() and max_heap_left.top()
        If heaps are unbalanced,then median is defined
        as the top element of heap of larger size  */
    for (int i = 1; i < arr.size(); i++)
    {
        double x = arr[i];

        // case1(left side heap has more elements)
        if (s.size() > g.size())
        {
            if (x < med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else {
                g.push(x);
            }

            med = (s.top() + g.top())/2.0;
        }

        // case2(both heaps are balanced)
        else if (s.size() == g.size())
        {
            if (x < med)
            {
                s.push(x);
                med = (double)s.top();
            }
            else
            {
                g.push(x);
                med = (double)g.top();
            }
        }

        // case3(right side heap has more elements)
        else
        {
            if (x > med)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else {
                s.push(x);
            }

            med = (s.top() + g.top())/2.0;
        }

        cout << med << endl;
    }
}

int main()
{
    vector<int> arr = {5, 15, 10, 20, 3};
    find_stream_median(arr); // 5 10 5 7.5 7.5

    cout << "--------" << endl;
    arr = {3, 5, 10}; // 3 4 5
    find_stream_median(arr); //

    cout << "--------" << endl;
    arr = {3, 5, 6, 10}; // 3 4 5 5.5
    find_stream_median(arr); //

    cout << "--------" << endl;
    arr = {-2, 10, 10, 10, 10, 8, 7, 4, 2, 1, 1, 1};
    find_stream_median(arr); //
}
