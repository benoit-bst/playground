#include <boost/filesystem.hpp>

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include <cstdio> // rename
#include <fstream>

using namespace std;
namespace fs = boost::filesystem;

/**
 * compile : g++ -lboost_filesystem-mt -lboost_system-mt filesystem.cpp
 */
int main(int argc, char const *argv[])
{

  // Le path Boost
  {

    fs::path p("/etc/apt/sources.list");

    std::cout << "Path        : " << p << std::endl;
    std::cout << "If exist    : " << fs::exists(p) << std::endl;
    std::cout << "File size   : " << fs::file_size(p) << std::endl;
    std::cout << "Parent path : " <<  p.parent_path() << std::endl;
    std::cout << "Root path   : " << p.root_path() << std::endl;
    std::cout << "Filename    : " << p.filename() << std::endl;

    // iteration
    for (fs::path::iterator it(p.begin()), it_end(p.end()); it != it_end; ++it){
      std::cout << " " << *it << std::endl;
    }

    // is a regular file
    std::cout << "Is regular file : " << fs::is_regular_file(p) << std::endl;

    p = "/etc/apt";
    std::cout << "Path : " << p << std::endl;

    // space function
    fs::space_info info = fs::space(p);
    std::cout << "Space info : " << info.capacity << " - " << info.free << " - " << info.available << std::endl;

    // directory
    std::cout << "Is directory : " << fs::is_directory(p) << std::endl;

    typedef vector< fs::path > vec;
    vec v;
    std::copy(fs::directory_iterator(p), fs::directory_iterator(), back_inserter(v));
    sort(v.begin(), v.end()); // files

    for (vec::const_iterator it(v.begin()), it_end(v.end()); it != it_end; ++it){
      std::cout << "files : " << *it << std::endl;
    }

    // Extension
    string filename = "/etc/apt/apt-file.conf";
    string ext = fs::extension(filename);
    std::cout << "Extension : " << ext << std::endl;
  }

  // Try
  {
    try
    {
      fs::path p("/etczefezfzfe/efdgzzzf/sources.list");
      std::cout << "File size : " << fs::file_size(p) << std::endl;
    }
    catch (const fs::filesystem_error& ex)
    {
      std::cout << "Error catch : " << ex.what() << std::endl;
    }
  }

  {
    // boost create directory
    bool error = fs::create_directory("./kikou");

    // std create file
    ofstream file ("./kikou/file_de_test.data");
    file << "test d'ecriture " << std::endl;
    file.close();

    // std rename file
    std::string newName = "./kikou/file_de_test_renamed.data";
    rename("./kikou/file_de_test.data", newName.c_str());

    // copy file boost
    fs::copy_file("./kikou/file_de_test_renamed.data", "./kikou/file_de_test_renamed_copy.data");

    // std remove bool == 0 veut dire copy ok
    error = remove("./kikou/file_de_test_renamed.data");

  }


  return 0;
}