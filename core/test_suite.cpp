#include "test_suite.hpp"

#include <algorithm>
#include <iostream>
#include <typeinfo>

using namespace evias;
using namespace unit_test;

suite::suite()
{

}

suite::suite(std::initializer_list<test*> tests)
        : tests_(tests)
{

}

bool suite::run()
{
    for (auto t : tests_) {
        message_t type;
        std::string res = "Result for '" + t->getName() + "':";

        try {
            /* XXX static_cast */
            (*t)();

            type = INFO;
            res += " [SUCCESS]";
        }
        catch (test_exception e) {

            std::cout << e.what() << std::endl;

            type = ERROR;
            res += " [FAILURE]";
        }

        print(res, type);
    }

    return true;
}

void suite::print(std::string msg, message_t type)
{
    std::string prefix;
    switch(type) {
        case INFO:
            prefix = "[INFO]";
            break;
        default:
            prefix = "[ERROR]";
    }

    std::cout << prefix << " " << msg << std::endl;
}