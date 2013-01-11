#include "variadic_templates.hpp"

#include <iostream>

using namespace evias;
using namespace unit_test;

test_variadic_templates::test_variadic_templates(std::string n)
    : test(n)
{
}

bool test_variadic_templates::operator()()
{
    using unit_test::addition;
    using unit_test::multiplication;

    int sum  = addition<1, 2, 3>::value;
    int mult = multiplication<1, 2, 3>::value;

    if (sum != 6)
        return false;

    if (mult != 6)
        return false;

    /* Fibonacci it! */
    sum = addition<0,1,1,2,3,5,8,13,21,34,55,89,144>::value;

    /**
     * Careful with multiplication, as the variadic template is
     * split into first and rest template arguments, the
     * multiplication result for 'rest' should not overflow
     * the biggest possible int.
     **/
    mult = multiplication<0,1,1,2,3,5,8,13,21,34>::value;

    if (sum != 376)
        return false;

    if (mult != 0)
        return false;

    return true;
}
