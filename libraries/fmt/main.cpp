#include <iostream>
#include <string>

#include <fmt/core.h>

using namespace std;

int main(int argc, char* argv[])
{
    fmt::print("The answer is {}.", 42);

    std::string s = fmt::format("{0}{1}{0}", "abra", "cad");
    fmt::print("The answer is {}.", s);

    return 0;
}
