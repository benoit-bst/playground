#include <iostream>
#include <string_view>

/*
 * compile : g++-7 -std=c++17 test_string_view.cpp
 *
 * A Slice of const contener.
 * Very usefull to compare std::string const.
 * More fast than std:srting == std::string (create new with std::string)   
 */
 
void* operator new(std::size_t n)
{
    std::cout << "[allocating " << n << " bytes]\n";
    return malloc(n);
}

bool compare(std::string_view s1, std::string_view s2)
{
    if (s1 == s2)
        return true;
    std::cout << '\"' << s1 << "\" does not match \"" << s2 << "\"\n";
    return false;
}

int main()
{
    std::string str = "this is my input string";

    std::string_view sv(&str.at(str.find_first_of('m')));

    compare(str, sv);

    return 0;
}
