#include "hello_world_impl.hpp"
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

shared_ptr<HelloWorld> HelloWorld::create() {
    return make_shared<HelloWorldImpl>();
}

HelloWorldImpl::HelloWorldImpl() {

}

string HelloWorldImpl::get_hello_world() {

    string myString = "Hello World! ";

    time_t t = time(0);
    tm now=*localtime(&t);
    char tmdescr[200]={0};
    const char fmt[]="%r";
    if (strftime(tmdescr, sizeof(tmdescr)-1, fmt, &now)>0) {
        myString += tmdescr;
    }
    std::ostringstream ss;
     ss << CV_VERSION_MAJOR;
    myString += "OPEN CV VERSION " + ss.str();
    return myString;

}
