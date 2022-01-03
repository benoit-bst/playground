#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

// is pal ?
// time complexity O(number of digit)
// space complexity O(1)
bool number_is_palindrome(long long input_val)
{
    bool is_pal = false;

    // limit min
    if (input_val >= 0 && input_val < 10)
        return true;

    // limit max
    if (input_val < 0 && input_val > 10000000000) {
        std::cerr << "out of range";
        return is_pal;
    }

    std::string input_string = std::to_string(input_val);
    std::string reverse_string(input_string);
    reverse(reverse_string.begin(), reverse_string.end());

    if (input_string == reverse_string) {
        return true;
    } else {
        return false;
    }
}

// is pal ?
// time complexity O(number of digit / 2)
// space complexity O(1)
bool number_is_palindrome_2(long long input_val)
{
    bool is_pal = false;

    // limit min
    if (input_val >= 0 && input_val < 10)
        return true;

    // limit max
    if (input_val < 0 && input_val > 10000000000) {
        std::cerr << "out of range";
        return is_pal;
    }

    std::string input_string = std::to_string(input_val);

    // Traversing through the string
    for (int i = 0; i < input_string.length() / 2; ++i) {

        if (input_string[i] != input_string[input_string.length() -1 - i])
            return false;
    }
    return true;
}

/* Driver program */
// g++ -std=c++11 numeric_palindrome.cpp
int main()
{
    int val = 3;
    cout << "is pal " << number_is_palindrome(val) << endl;
    cout << "is pal " << number_is_palindrome_2(val) << endl;
    val = 36;
    cout << "is pal " << number_is_palindrome(val) << endl;
    cout << "is pal " << number_is_palindrome_2(val) << endl;
    val = 363;
    cout << "is pal " << number_is_palindrome(val) << endl;
    cout << "is pal " << number_is_palindrome_2(val) << endl;
    val = 123;
    cout << "is pal " << number_is_palindrome(val) << endl;
    cout << "is pal " << number_is_palindrome_2(val) << endl;
    val = 39993;
    cout << "is pal " << number_is_palindrome(val) << endl;
    cout << "is pal " << number_is_palindrome_2(val) << endl;
    val = 39997;
    cout << "is pal " << number_is_palindrome(val) << endl;
    cout << "is pal " << number_is_palindrome_2(val) << endl;
	return 0;
}

