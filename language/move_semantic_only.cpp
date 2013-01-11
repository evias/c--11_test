#include "move_semantic_only.hpp"

using namespace evias;
using namespace unit_test;

test_move_semantic::test_move_semantic(std::string n)
    : test(n)
{
}

test_move_semantic::test_move_semantic(test_move_semantic&& rh)
    : test(rh.getName()), content_(std::move(rh.content_))
{
}

test_move_semantic& test_move_semantic::operator=(test_move_semantic&& rh)
{
    content_ = std::move(rh.content_);
    return *this;
}

void test_move_semantic::setContent(int c)
    throw()
{
    content_ = c;
}

bool test_move_semantic::operator()()
{
    setContent(5);

    if (content_ != 5)
        return false;

    setContent(-4);

    if (content_ != -4)
        return false;

    return true;
}