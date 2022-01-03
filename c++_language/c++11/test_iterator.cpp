#include <iostream>
#include <vector>
#include <stdexcept>

/**
 * @brief test iterator handling
 */
template<class Container>
class Handler
{
public:

    typedef typename Container::iterator It;
    typedef typename Container::pointer Pointer;
    typedef typename Container::value_type T;

    Handler(Container & container)
        : _pointer(container.data()),
        _pointer2(container.data()),
        _begin(container.begin()),
        _end(container.end())
    {
        if (_begin == _end)
            throw std::length_error("Container should not be empty");
    }

private:

    T* _pointer;
    Pointer _pointer2;
    It _begin;
    It _end;

};

/**
 *  g++ -std=c++11 test_iterator.cpp
 */
int main(int argc, char const *argv[])
{
    std::vector<int> input = {1, 2, 3, 4, 5};
    Handler<std::vector<int>> handler(input);
    return 0;
}
