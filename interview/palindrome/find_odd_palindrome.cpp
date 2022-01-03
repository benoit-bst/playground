#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

string check_window(string input, int idx) {

    string pal = "";
    int window_length = 0;
    if (input.size() - idx > idx) {
         window_length = idx;
    } else {
         window_length= input.size() - idx;
    }
    pal = input[idx];
    for (int i = 1; i < window_length; ++i) {

        if (input[idx - i] != input[idx + i] && input[idx + i] != input[idx] && input[idx - i] != input[idx]) {
            break;
        } else if (input[idx - i] == input[idx + i]) {
            pal = input[idx - i] + pal + input[idx + i];
        } else if (input[idx - i] == input[idx]) {
            pal = input[idx - i] + pal;
        } else if (input[idx + i] == input[idx]) {
            pal = pal + input[idx + i];
        } else {
            std::cerr << "out  of scope";
        }

    }
    return pal;
}

// time complexity O(N*N/2)
// space complexity O(N)
set<string> find_palindrome(string& input)
{
    set<string> pal_list;

    // min
    if (input.length() <= 1 )
        return {input};

    if (input.length() > 1 )
        pal_list.insert(string(1, input[0]));

    // for each char
    for (int i = 1; i < input.length(); ++i) {
        pal_list.insert(check_window(input, i));
    }

    return pal_list;
}

void print_pal(const set<string> input) {
    cout << "pal list size: " << input.size() << endl;
    for (auto s : input) {
        cout << s << endl;
    }
}

/* Driver program */
// g++ -std=c++11 find_palindrome.cpp
int main()
{
    string val = "a";
    auto pal_list = find_palindrome(val);
    print_pal(pal_list);
    val = "ab";
    pal_list = find_palindrome(val);
    print_pal(pal_list);
    val = "abc";
    pal_list = find_palindrome(val);
    print_pal(pal_list);
    val = "zqabsbadesc";
    pal_list = find_palindrome(val);
    print_pal(pal_list);
    val = "abcccdes";
    pal_list = find_palindrome(val);
    print_pal(pal_list);
    val = "abcdcba";
    pal_list = find_palindrome(val);
    print_pal(pal_list);
    val = "azertyubddb";
    pal_list = find_palindrome(val);
    print_pal(pal_list);
    val = "azertyubddbqe";
    pal_list = find_palindrome(val);
    print_pal(pal_list);
    val = "aaaaaaaaabcdcbaaaaagrdghjjliuytrezaaddaa";
    pal_list = find_palindrome(val);
    print_pal(pal_list);
	return 0;
}

