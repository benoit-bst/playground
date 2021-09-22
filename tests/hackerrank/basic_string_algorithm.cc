
//*********************************
// SPLIT
//*********************************

// first element of the split
string lol = "one;two";
std::string delimiter = ";";
std::string token = lol.substr(0, lol.find(delimiter));


// all element after a split
std::string s = "scott>=tiger>=mushroom";
delimiter = ">=";

size_t pos = 0;
token;
while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    std::cout << "PI " << token << std::endl;
    s.erase(0, pos + delimiter.length());
}
std::cout << s << std::endl;


//*********************************
// TRIM
//*********************************

// trim all element with boost
#include <boost/algorithm/string.hpp>
using namespace boost::algorithm;

string str1 = "Hello and Welcome Hello and Welcome";
  cout<<str1<<endl;
  erase_all(str1,"Hello ");
  cout<<str1<<endl;

// trim the first and the last
kikou_string.erase(0, 1);
kikou_string.erase(kikou_string.size() - 1);

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

std::string trim(const std::string &s) {
    return rtrim1(ltrim1(s));
}


//*********************************
// TO LOWER
//*********************************

// to lower with boost
#include <boost/algorithm/string.hpp>

std::string str = "HELLO, WORLD!";
boost::algorithm::to_lower(str);
const std::string lower_str = boost::algorithm::to_lower_copy(str);

// with std
std::string data = "Abc";
    std::transform(data.begin(), data.end(), data.begin(),
        [](unsigned char c){ return std::tolower(c); });

// with std and shift
char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}
std::transform(data.begin(), data.end(), data.begin(), asciitolower);
std::transform(data.begin(), data.end(), data.begin(), ::toupper);


//*********************************
// COUNT
//*********************************
std::string s = "a_b_c";
size_t n = std::count(s.begin(), s.end(), '_');
cout << " kikou " << n << endl;


//*********************************
// REVERSE
//*********************************
std::string s = "a_b_c";
std::reverse(s.begin(), s.end());

for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);


//*********************************
// FIND
//*********************************
std::string s = "this is text";
size_t idx = str.find('i');
if (idx!=std::string::npos)
    cout << idx << endl;
idx = str.find('i', idx + 1);
