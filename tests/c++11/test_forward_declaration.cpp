#include <iostream>

namespace test {

  class Data{
  public:
    void function1() {int b = 0;};
    int function1(int a) {return a;};

  };

}

template<typename Data>
class DataManager{
public:
    DataManager() {
      Data* data = new Data;
      data->function1();

    }
};
// Vector
// compile : g++ -std=c++11 test_forward_declaration.cpp
int main()
{
  DataManager<test::Data> kikou;


}