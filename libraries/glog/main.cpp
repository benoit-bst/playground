#include <iostream>
#include <string>

#include <glog/logging.h>

using namespace std;

//
// run for console :
// GLOG_logtostderr=1 ./test
//
//
//
int main(int argc, char* argv[])
{
    google::InitGoogleLogging(argv[0]);

    // debug mode only if we compil with DEBUG
    DLOG(INFO) << "Found cookies";

    LOG(INFO) << "This is an info  message";
    LOG(WARNING) << "This is a warning message";
    LOG(ERROR) << "This is an error message";
    // LOG(FATAL) << "This is a fatal message"; // aborted

    VLOG(1) << "I'm printed when you run the program with --v=1 or higher";
    VLOG(2) << "I'm printed when you run the program with --v=2 or higher";

    return 0;
}
