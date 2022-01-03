#include <iostream>
#include <vector>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/bitset.hpp>

using namespace std;

/*
 * compile : g++ -std=c++11 test_sizeof_stoptime.cpp
 */
int main()
{
  {
    class StopTime1
    {
      StopTime1(){};
      boost::shared_ptr<int> shape_from_prev;
      int* vehicle_journey = nullptr;
      int* stop_point = nullptr;
      uint32_t arrival_time = 0;
      uint32_t departure_time = 0;
      uint32_t boarding_time;
      uint32_t alighting_time;
      uint16_t local_traffic_zone;
      //std::bitset<8> properties;
      char a;
    };
    cout << "sizeof StopTime1 : " << sizeof(StopTime1) << endl;
  }
  {
    class StopTime1
    {
      StopTime1(){};
      std::bitset<8> properties;
      uint16_t local_traffic_zone;
      uint32_t arrival_time = 0;
      uint32_t departure_time = 0;
      uint32_t boarding_time;
      uint32_t alighting_time;
      int* vehicle_journey = nullptr;
      int* stop_point = nullptr;
      boost::shared_ptr<int> shape_from_prev;
    };
    cout << "sizeof StopTime1 : " << sizeof(StopTime1) << endl;
  }
  {
    boost::shared_ptr<int> shape_from_prev;
    cout << "sizeof StopTime1 : " << sizeof(shape_from_prev) << endl;
  }
  {
    std::bitset<8> properties;
    cout << "sizeof StopTime1 : " << sizeof(properties) << endl;
  }
  {
    char properties;
    cout << "sizeof StopTime1 : " << sizeof(properties) << endl;
  }
  {
    std::bitset<1> properties;
    cout << "sizeof StopTime1 : " << sizeof(properties) << endl;
  }
  {
    std::bitset<10> properties;
    cout << "sizeof StopTime1 : " << sizeof(properties) << endl;
  }
  {
    std::bitset<32> properties;
    cout << "sizeof StopTime1 : " << sizeof(properties) << endl;
  }
  {
    std::bitset<33> properties;
    cout << "sizeof StopTime1 : " << sizeof(properties) << endl;
  }
  {
    std::bitset<64> properties;
    cout << "sizeof StopTime1 : " << sizeof(properties) << endl;
  }
  {
    std::bitset<65> properties;
    cout << "sizeof StopTime1 : " << sizeof(properties) << endl;
  }
  {
    std::bitset<366> properties;
    cout << "sizeof StopTime1 : " << sizeof(properties) << endl;
  }
}
