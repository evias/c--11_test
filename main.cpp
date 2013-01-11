/*
 * File:   main.cpp
 * Author: greg
 *
 * Created on January 5, 2013, 5:49 PM
 */

#include "core/test.hpp"
#include "core/test_suite.hpp"

#include "language/range_based_for.hpp"

using namespace std;
using namespace evias;

int main(int argc, char** argv)
{
    auto thesuite = new unit_test::suite({
        new unit_test::test_range_based_for<std::map<std::string,std::string>>("Range based For-loop <map<string, string>>"),
        new unit_test::test_range_based_for<std::vector<std::string>>("Range based For-loop <vector<string>>")});

    thesuite->run();

    return 0;
}

