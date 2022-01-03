#include <iostream>
#include <fstream>

#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filter/bzip2.hpp>
#include <boost/iostreams/copy.hpp>

using namespace std;
namespace io = boost::iostreams;

/**-z
 * compile : g++ -lboost_iostreams iostreams.cpp
 */
int main(int argc, char const *argv[])
{
  {
    ifstream file("compress/compressFile.tar.gz", ios_base::in | ios_base::binary);
    io::filtering_streambuf<io::input> in;
    in.push(io::gzip_decompressor());
    in.push(file);
    io::copy(in, cout);
  }

  {
    ifstream file("compress/compressFile.bz2", ios_base::in | ios_base::binary);
    io::filtering_streambuf<io::input> in;
    in.push(io::bzip2_decompressor());
    in.push(file);
    io::copy(in, cout);
  }

  return 0;
}