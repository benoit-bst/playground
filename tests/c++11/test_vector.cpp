#include <iostream>
#include <vector>
#include <algorithm>

// Vector
// compile : g++ -std=c++11 test_vector.cpp
int main()
{
  std::cout << "Vector :" << std::endl << std::endl;
  
  std::vector<int> v1 = {1,2,3,4,5};
  std::cout << "v1 size     : " << v1.size() << std::endl;
  std::cout << "v1 max size : " << v1.max_size() << std::endl;
  std::cout << "v1 capacity : " << v1.capacity() << std::endl;
  std::cout << "v1 reserve 10 " << std::endl;
  v1.reserve(10);
  std::cout << "v1 capacity : " << v1.capacity() << std::endl;
  std::cout << "v1 shrink_to_fit" << std::endl;
  v1.shrink_to_fit();
  std::cout << "v1 capacity : " << v1.capacity() << std::endl;
  
  // classic loop
  std::cout << "v1 classic loop : ";
  for (int i = 0; i < v1.size(); i++){
     std::cout << v1[i] << " ";
  }
  std::cout << std::endl;
  
  // loop c++ 11
  std::cout << "v1 loop c++ 11 : ";
  for (auto elem : v1){
     std::cout << elem << " ";
  }
  std::cout << std::endl;
  
  // iterator loop
  std::cout << "v1 iterator loop : ";
  for (std::vector<int>::iterator it = begin(v1); it != end(v1); it++){
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  
  // const iterator loop
  std::cout << "v1 const iterator loop : ";
  for (auto it = v1.cbegin(); it != v1.cend(); it++){
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  
  // invert iterator loop
  std::cout << "v1 invert iterator loop : ";
  for (std::vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++){
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  
  // for each loop
  std::cout << "v1 for each loop : ";
  std::for_each(v1.begin(), v1.end(), [](int &n){ std::cout << n << " ";});
  std::cout << std::endl;
  
  // .data()
  auto* p = v1.data();
  std::cout << "v1 .data() : ";
  for (int i = 0; i < v1.size(); i++){
     std::cout << p[i] << " ";
  }
  std::cout << std::endl;
}
