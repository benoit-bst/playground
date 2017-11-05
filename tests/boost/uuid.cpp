#include <iostream>
#include <fstream>
#include <vector>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace boost::uuids;
using namespace std;
/**
 * compile : g++ uuid.cpp
 */
int main(int argc, char const *argv[])
{
  {
    random_generator gen;
    uuid id = gen();
    std::cout << "Id " << id << std::endl;
    std::cout << "Size " << id.size() << std::endl;
    std::cout << "Variant " << id.variant() << std::endl;
    std::cout << "Version " << id.version() << std::endl;
  }

  {
    random_generator gen;
    uuid id = gen();
    std::cout << "Id " << id << std::endl;
    std::cout << "Size " << id.size() << std::endl;
    std::cout << "Variant " << id.variant() << std::endl;
    std::cout << "Version " << id.version() << std::endl;

    std::string idStr = to_string(id);
    std::cout << "Id " << idStr << std::endl;

    vector<char> v(id.size());
    copy(id.begin(), id.end(), v.begin());
    for (int i = 0; i < v.size(); ++i)
    {
      std::cout << v[i];
    }
    std::cout << std::endl;
  }

  return 0;
}