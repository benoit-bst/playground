#include <bits/stdc++.h>

#include <cmath>
using namespace std;

// O(N)
// O(N)
void move_zero_to_the_left(vector<int>& in) {

    vector<int> buff;
    int count_zero = 0;
    for (int i =0; i < in.size(); ++i) {
        if (in[i] == 0) {
            count_zero++;
            buff.push_back(0);
        }
    }

    for (int i = 0; i < in.size(); ++i) {
        if (in[i] != 0) {
            buff.push_back(in[i]);
        }
    }
    in = buff;
}

// O(N)
// O(1)
void move_zero_to_the_left_2(vector<int>& in) {

    if (in.size() < 1) return;

    int write_index = in.size() - 1;
    int read_index = in.size() - 1;

    while(read_index >= 0) {
        if(in[read_index] != 0) {
            in[write_index] = in[read_index];
            write_index--;
        }
        read_index--;
    }

    while(write_index >= 0) {
        in[write_index] = 0;
        write_index--;
    }
}

// O(N)
// O(N)
void move_zero_to_the_right(vector<int>& in) {

    int count_zero = 0;
    for (int i =0; i < in.size(); ++i) {
        if (in[i] == 0) {
            count_zero++;
        }
    }

    vector<int> buff;
    for (int i = 0; i < in.size(); ++i) {
        if (in[i] != 0) {
            buff.push_back(in[i]);
        }
    }
    for (int i = 0; i < count_zero; ++i) {
        buff.push_back(0);
    }
    in = buff;
}

// O(N)
// O(1)
void move_zero_to_the_right_2(vector<int>& in) {

    int count = 0;
    for (int i =0; i < in.size(); ++i) {
        if (in[i] != 0) {
            in[count] = in[i];
            count++;
        }
    }
    while (count < in.size()) {
        in[count++] = 0;

    }
}

int main()
{
    {
        vector<int> in = {1, 2, 6, 4, 10, 3, 0, 0, 0, 7, 9, 0};
        for (auto& val : in) {
            cout << val << " ";
        } cout << endl;

        move_zero_to_the_left(in);

        for (auto& val : in) {
            cout << val << " ";
        } cout << endl;

    }
    {
        vector<int> in = {1, 2, 6, 4, 10, 3, 0, 0, 0, 7, 9, 0};
        for (auto& val : in) {
            cout << val << " ";
        } cout << endl;

        move_zero_to_the_left_2(in);

        for (auto& val : in) {
            cout << val << " ";
        } cout << endl;

    }
    {
        vector<int> in = {1, 2, 6, 4, 10, 3, 0, 0, 0, 7, 9, 0};
        for (auto& val : in) {
            cout << val << " ";
        } cout << endl;

        move_zero_to_the_right(in);

        for (auto& val : in) {
            cout << val << " ";
        } cout << endl;

    }
    {
        vector<int> in = {1, 2, 6, 4, 10, 3, 0, 0, 0, 7, 9, 0};
        for (auto& val : in) {
            cout << val << " ";
        } cout << endl;

        move_zero_to_the_right_2(in);

        for (auto& val : in) {
            cout << val << " ";
        } cout << endl;
    }

    return 0;
}
