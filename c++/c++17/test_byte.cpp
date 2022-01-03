#include <iostream>
#include <cstddef>

/*
 * compile : g++-7 -std=c++17 test_byte.cpp
 *
 * Implement the concept of byte.
 * static method :
 * - std::to_integer
 * - std::byte{integer}
 *
 * operator : << >> | & ~ ^
 */

int main()
{
    std::byte b{10};
    
    std::cout << int(10) << std::endl;

    return 0;
}
