#include <bits/stdc++.h>

using namespace std;

// O(N+K) where n is the number of elements in input array and k is the range of input.
// O(N+K)
vector<int> counting_sort(vector<int> arr) {

    if (arr.size() == 0)
        return vector<int>();

    int i, j;
    // to be fast, we need to fix the max size directly
    // So we have to know our input
    //int a[100]={0};
    auto finded_max = std::max_element(arr.begin(), arr.end());
    vector<int> a(*finded_max + 1, 0);

    // frequency array
    for(i = 0; i < arr.size(); i++) {
        (a[arr[i]])++;
    }

    vector<int>v;
    for(i = 0; i < *finded_max + 1; i++)
    {
        while(a[i] != 0)
        {
            v.push_back(i);
            (a[i])--;
        }
    }
    return v;
}

void countSort(vector<int>& arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

int main()
{
    vector<int> c = {4, 3, 5, 1, 2};
    auto res = counting_sort(c); // 1 2 3 4 5
    for (const auto& _val : res) {
        cout << _val << " ";

    }cout << endl;

    c = {2, 3, 1, 1, 4};
    res = counting_sort(c); // 1 1 2 3 4
    for (const auto& _val : res) {
        cout << _val << " ";
    }cout << endl;

    c = {1};
    res = counting_sort(c); // 1
    for (const auto& _val : res) {
        cout << _val << " ";
    }cout << endl;

    c = {};
    res = counting_sort(c); //
    for (const auto& _val : res) {
        cout << _val << " ";
    }cout << endl;

    // WITH NEG
    c = {-2, 3, 1, -1, 4};
    countSort(c); //-2 -1 1 3 4
    for (const auto& _val : c) {
        cout << _val << " ";
    }cout << endl;

    return 0;
}
