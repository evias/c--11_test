#include "move_semantic_only.hpp"

using namespace evias;
using namespace unit_test;

/**
 * Class test_move_semantic
 */
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

/**
 * Class test_move_assignments
 */
test_move_assignments::test_move_assignments(std::string n)
    : test(n)
{
}

bool test_move_assignments::operator()()
{
    int lvalue1 = 5;
    int lvalue2 = 6;

    int rvalue1 = std::move(lvalue1);
    int rvalue2 = std::move(lvalue2);

    if (rvalue1 != lvalue1)
        return false;

    if (rvalue2 != lvalue2)
        return false;

    return true;
}