// C++ program to find longest Zig-Zag subsequence in
// an array
// g++ -std=c++11 longest_zigzag_sequence.cpp
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Function to return longest Zig-Zag subsequence length
// time complexity O(N*(N-1)/2) = O(N^2)
// space complexity O(1)
int zzis_2(vector<int>& seq)
{
    int counter = 0;
    bool flag = true;
    int res = 0;

	for (int i = 0; i < seq.size() - 1; ++i)
	{
        // at the start
        if (seq[i] > seq[i + 1]) {
            flag = true; // we start with a negatif
        } else {
            flag = false; // we start with a positif
        }
        counter = 1;

		for (int j = i + 1; j < seq.size() - 1; ++j)
		{
            // want to find a positif
            if (flag) {
                if (seq[j] < seq[j + 1]) {
                    counter++;
                    flag = false;
                }
            }
            // want to find a negatif
            else {
                if (seq[j] > seq[j+ 1]) {
                    counter++;
                    flag = true;
                }
            }
		}
        if (counter > res) {
            res = counter;
        }
	}
    return res;
}


int signum(int n)
{
    if (n != 0) {
        return n > 0 ? 1 : -1;
    } else {
        return 0;
    }
}

// Function to calculate maximum length of zig-zag
// sub-sequence in given sequence.
// time complexity O(N)
// space complexity O(1)
int maxZigZag(vector<int> seq)
{
    if (seq.empty()) {
        return 0;
    }

    int lastSign = 0, length = 0;

    // Length is initialized to 1 as
    // that is minimum value
    // for arbitrary sequence.
    for (int i = 1; i < seq.size(); ++i) {
        int Sign = signum(seq[i] - seq[i - 1]);

        // It qualifies
        if (Sign != lastSign && Sign != 0)
        {

            // Updating lastSign
            lastSign = Sign;
            length++;
        }
    }
    return length;
}

/* Driver program */
int main()
{
    vector<int> seq = { 10 };
    cout << "Length of Longest Zig-Zag subsequence is " << zzis_2(seq) << endl; // 0
    cout << "Length of Longest Zig-Zag subsequence is " << maxZigZag(seq) << endl << endl; // 0
    seq = { 10 , 20};
    cout << "Length of Longest Zig-Zag subsequence is " << zzis_2(seq) << endl; // 1
    cout << "Length of Longest Zig-Zag subsequence is " << maxZigZag(seq) << endl << endl; // 1
    seq = { 40, 30, 20, 10};
    cout << "Length of Longest Zig-Zag subsequence is " << zzis_2(seq) << endl; // 1
    cout << "Length of Longest Zig-Zag subsequence is " << maxZigZag(seq) << endl << endl; // 1
    seq = { 10, 20, 30, 40};
    cout << "Length of Longest Zig-Zag subsequence is " << zzis_2(seq) << endl; // 1
    cout << "Length of Longest Zig-Zag subsequence is " << maxZigZag(seq) << endl << endl; // 1
    seq = { 10, 22, 9, 33, 49, 30};
    cout << "Length of Longest Zig-Zag subsequence is " << zzis_2(seq) << endl; // 4
    cout << "Length of Longest Zig-Zag subsequence is " << maxZigZag(seq) << endl << endl; // 0
    seq = { 10, 22, 9, 33, 49, 50};
    cout << "Length of Longest Zig-Zag subsequence is " << zzis_2(seq) << endl; // 3
    cout << "Length of Longest Zig-Zag subsequence is " << maxZigZag(seq) << endl << endl; // 0
    seq = {10, 22, 9, 33, 49, 50, 31, 60};
    cout << "Length of Longest Zig-Zag subsequence is " << zzis_2(seq) << endl; // 5
    cout << "Length of Longest Zig-Zag subsequence is " << maxZigZag(seq) << endl << endl; // 0
	return 0;
}

