#include <bits/stdc++.h>

using namespace std;

// Time  : O(N)
// space : O(N)
vector<int> array_left_rotation(vector<int>& a, int k) {

    uint input_size = a.size();

    // edge cases
    if (input_size == k || k <= 0 || input_size == 0) {
        return a;
    }

    // modulo
    k %= input_size;

    vector<int> vec(input_size);
    for(int i = 0; i < input_size; i++) {
        vec[( input_size + i - k) % input_size] = a[i];
    }
    return vec;
}

void print(const vector<int>& in) {
    for(const auto& _val : in)
        cout << _val << " ";
    cout << endl;
}

int main(){
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 3;
    print(array_left_rotation(a, k)); // 3 4 5 6 7 8 9 0 1 2

    a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    k = 8;
    print(array_left_rotation(a, k)); // 8 9 0 1 2 3 4 5 6 7

    a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    k = 12;
    print(array_left_rotation(a, k)); // 2 3 4 5 6 7 8 9 0 1

    a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    k = 10;
    print(array_left_rotation(a, k)); // 0 1 2 3 4 5 6 7 8 9

    a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    k = 0;
    print(array_left_rotation(a, k)); // 0 1 2 3 4 5 6 7 8 9

    a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    k = -1;
    print(array_left_rotation(a, k)); // 0 1 2 3 4 5 6 7 8 9

    a = {};
    k = 4;
    print(array_left_rotation(a, k)); // nope

    a = {0, 1, 2, 3};
    k = 2;
    print(array_left_rotation(a, k)); // 2 3 0 1

    return 0;
}
