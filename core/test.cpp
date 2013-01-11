#include "test.hpp"

using namespace evias;
using namespace unit_test;

test_exception::test_exception(std::string m)
    : msg_(m)
{
}

const char* test_exception::what()
    const throw()
{
    return msg_.c_str();
}

test::test(std::string n)
        : name_(n)
{
}

void test::setName(std::string n)
{
    name_ = n;
}

std::string test::getName()
{
    return name_;
}

bool test::operator()()
{
    throw test_exception("Please overload operator().");
}
