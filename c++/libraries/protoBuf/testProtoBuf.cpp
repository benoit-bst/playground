#include <iostream>
#include <fstream>
#include "test.pb.h"

using namespace std;
using namespace foo;


// protoc  --cpp_out=. test.proto
// compile : g++ -std=c++11 -lprotobuf -pthread -L /home/cjg347/dev/compiletutorial/protoBuf testProtoBuf.cpp test.pb.cc
int main()
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	foo::Point p;
	p.set_x(10);
	p.set_y(20);
  cout << "x " << p.x() << "\n";
  cout << "y " << p.y() << "\n";

  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}