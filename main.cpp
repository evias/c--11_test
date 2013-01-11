/*
 * File:   main.cpp
 * Author: greg
 *
 * Created on January 5, 2013, 5:49 PM
 */

#include "core/test.hpp"
#include "core/test_suite.hpp"

#include "language/range_based_for.hpp"
#include "language/move_semantic_only.hpp"

using namespace std;
using namespace evias;

int main(int argc, char** argv)
{
    /* Improve readability. */
    using std::map;
    using std::vector;
    using std::array;
    using std::string;

    using unit_test::test_range_based_for;
    using unit_test::test_move_semantic;

    using test_map_rbfor    = test_range_based_for<map<int,string>>;
    using test_vector_rbfor = test_range_based_for<vector<string>>;
    using test_array_rbfor  = test_range_based_for<array<string,3>>;

    auto evias_suite = new unit_test::suite("eVias C++11");

    /* Instanciate the unitary test suite. */
    auto rbfor_suite = new unit_test::suite("Range based for-loop", {
        new test_map_rbfor("Range based For-loop <map<string, string>>"),
        new test_vector_rbfor("Range based For-loop <vector<string>>"),
        new test_array_rbfor("Range based For-loop <array<string,3>>")});

    auto mvsem_suite = new unit_test::suite("Move semantic classes", {
        new test_move_semantic("'Move semantic'-only c++11 class definition")});

    evias_suite->addSuite(rbfor_suite);
    evias_suite->addSuite(mvsem_suite);
    evias_suite->run();

    delete rbfor_suite;
    delete mvsem_suite;
    delete evias_suite;

    return 0;
}

