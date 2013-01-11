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
    /* Improve readability. */
    using unit_test::test_range_based_for;
    using std::map;
    using std::vector;
    using std::array;
    using std::string;

    using test_map_rbfor    = test_range_based_for<map<string,string>>;
    using test_vector_rbfor = test_range_based_for<vector<string>>;
    using test_array_rbfor  = test_range_based_for<array<string,3>>;

    /* Instanciate the unitary test suite. */
    auto thesuite = new unit_test::suite({
        new test_map_rbfor("Range based For-loop <map<string, string>>"),
        new test_vector_rbfor("Range based For-loop <vector<string>>"),
        new test_array_rbfor("Range based For-loop <array<string,3>>")});

    thesuite->run();
    return 0;
}

