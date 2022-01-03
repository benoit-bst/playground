#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>

using namespace std;
using std::chrono::nanoseconds;
using std::chrono::duration_cast;

//******************************
// Linear search
// Sorted Data
// O(n)
int Linear_search(vector<int> & array, int x)
{
  for (int i = 0; i < array.size(); ++i)
  {
  	if (array[i] == x){
      return i;
  	}
  }
  return -1;
}

//******************************
// Binary search (Divide and conquer)
// Sorted Data
// O(log n)
int Binary_search(vector<int> & array, int x)
{
  int min = 0;
  int max = array.size() - 1;
  int mid = -1;

  while(min <= max)
  {
    mid = min + (max-min)/2;

    if (array[mid] == x) {return mid;}

    if (array[mid] < x) {min = mid + 1;}

    else {max = mid - 1;}
  }
  return -1;
}

//******************************
// Interpolation search
// Sorted Data
// O(log log n) pour une distribution uniforme
int Interpolation_search(vector<int> & array, int x)
{
  int min = 0;
  int max = array.size() - 1;
  int mid = -1;

  while(array[max] != array[min] && x >= array[min] && x <= array[max])
  {
  	long a = x - array[min];
  	long b = max-min;
  	long c = array[max] - array[min];
    mid = min + (a*b/c);

    if (array[mid] < x) {
      min = mid + 1;
    }
    else if (x < array[mid]){
      max = mid - 1;
    }
    else{
    	return mid;
    }
  }

  if (x == array[min]){
    return min;
  }
  else{
  	return -1;
  }
}

// compile : g++ -std=c++11 test_search.cpp
int main()
{
  int size = 10000000;
  int val = 5600000;
  vector<int> array;
  array.reserve(size);
  for (int i = 0; i < size; ++i){
  	array.push_back(i);
  }

  auto t1 = std::chrono::high_resolution_clock::now();
  int out = Linear_search(array, val);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto diff = t2 - t1;
  nanoseconds ns = duration_cast<nanoseconds>(diff);
  std::cout << "Linear_search  - " << ns.count() << " nano - " << out << std::endl;

  t1 = std::chrono::high_resolution_clock::now();
  out = Binary_search(array, val);
  t2 = std::chrono::high_resolution_clock::now();
  diff = t2 - t1;
  ns = duration_cast<nanoseconds>(diff);
  std::cout << "Binary_search  - " << ns.count() << " nano - " << out << std::endl;

  t1 = std::chrono::high_resolution_clock::now();
  out = binary_search(array.begin(), array.end(), val);
  t2 = std::chrono::high_resolution_clock::now();
  diff = t2 - t1;
  ns = duration_cast<nanoseconds>(diff);
  std::cout << "Std binary_search  - " << ns.count() << " nano - " << out << std::endl;

  t1 = std::chrono::high_resolution_clock::now();
  out = Interpolation_search(array, val);
  t2 = std::chrono::high_resolution_clock::now();
  diff = t2 - t1;
  ns = duration_cast<nanoseconds>(diff);
  std::cout << "Interpolation_search  - " << ns.count() << " nano - " << out << std::endl;

}
