#include <bits/stdc++.h>

#include <boost/algorithm/string.hpp>
using namespace boost::algorithm;

// to lower with boost
#include <boost/algorithm/string.hpp>

using namespace std;

// old method to trim
const std::string WHITESPACE = "<>'";
std::string ltrim1(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
std::string rtrim1(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
std::string trimy(const std::string &s) {
    return rtrim1(ltrim1(s));
}

// with std and shift
char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

int main() {

    {
        //*********************************
        // SPLIT
        //*********************************

        // first element of the split
        string s = "one;two";
        std::string delimiter = ";";
        std::string first = s.substr(0, s.find(delimiter));
        cout << "split " << first << endl; // one

        // all element after a split
        s = "scott>=tiger>=mushroom";
        delimiter = ">=";

        size_t pos = 0;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            auto token = s.substr(0, pos);
            std::cout << "split " << token << std::endl; // scott tiger mushroom
            s.erase(0, pos + delimiter.length());
        }
        std::cout << "split " << s << std::endl; // scott tiger mushroom
    }
    {
        //*********************************
        // TRIM
        //*********************************

        // trim all element with boost
        //#include <boost/algorithm/string.hpp>
        string str1 = "Hello and Welcome Hello and Welcome";
        erase_all(str1,"Hello ");
        cout << "trim " << str1 << endl; // trim and Welcome and Welcome

        // trim the first and the last
        string str2 = " Hello ";
        str2.erase(0, 1);
        str2.erase(str2.size() - 1);
        cout << "trim " << str2 << endl; // trim Hello

        string str3 = "<Hello < kikou'";
        cout << "trim " << trimy(str3) << endl; // trim Hello < kikou

    }
    {
        //*********************************
        // TO LOWER
        //*********************************

        // to lower with boost
        //#include <boost/algorithm/string.hpp>
        std::string str = "HELLO, WORLD!";
        boost::algorithm::to_lower(str);
        cout << "to_lower " << str << endl; // to_lower hello, world!
        str = "HELLO, WORLD!";
        const std::string lower_str = boost::algorithm::to_lower_copy(str);
        cout << "to_lower " << lower_str << endl; // to_lower hello, world!

        // with std
        std::string data = "ABC";
            std::transform(data.begin(), data.end(), data.begin(),
                [](unsigned char c){ return std::tolower(c); });
        cout << "to lower " << data << endl; // to lower abc

        data = "ABC";
        std::transform(data.begin(), data.end(), data.begin(), asciitolower);
        cout << "to lower " << data << endl; // to lower abc

        std::transform(data.begin(), data.end(), data.begin(), ::toupper);
        cout << "to upper " << data << endl; // to upper ABC
    }
    {
        //*********************************
        // COUNT
        //*********************************
        std::string s = "a_b_c";
        size_t n = std::count(s.begin(), s.end(), '_');
        cout << "count " << n << endl; // 2
    }
    {
        //*********************************
        // REVERSE
        //*********************************
        std::string s = "a_b_c";
        int n = s.size();
        std::reverse(s.begin(), s.end());
        cout << "reverse " << s << endl; //

        s = "a_b_c";
        for (int i = 0; i < n / 2; i++)
            swap(s[i], s[n - i - 1]);
        cout << "reverse " << s << endl; //
    }
    {
        //*********************************
        // FIND
        //*********************************
        std::string s = "this is text";
        size_t idx = s.find('i');
        if (idx!=std::string::npos)
            cout << "find " << idx << endl; // 2
        idx = s.find('i', idx + 1);
        if (idx!=std::string::npos)
            cout << "find " << idx << endl; // 5
    }

}
