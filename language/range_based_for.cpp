#include "range_based_for.hpp"

#include <iostream>

using namespace evias;
using namespace unit_test;

test_range_based_for<std::map<int,std::string>>::test_range_based_for(std::string n)
    : test(n)
{
}

bool test_range_based_for<std::map<int,std::string>>::operator()()
{
    std::map<int,std::string> container = {
        {1, "test1"},
        {2, "test2"}};

    for (auto it : container) {
        if (it.first != 1 && it.first != 2)
            return false;

        if (it.second != "test1" && it.second != "test2")
            return false;
    }

    return true;
}

test_range_based_for<std::vector<std::string>>::test_range_based_for(std::string n)
    : test(n)
{
}

bool test_range_based_for<std::vector<std::string>>::operator()()
{
    std::vector<std::string> container = {
        "firststr", "secondstr", "thirdstr"};

    int i = 0;
    for (auto it : container) {
        if (it != "firststr"
            && it != "secondstr"
            && it != "thirdstr")
            return false;
    }

    return true;
}

test_range_based_for<std::array<std::string,3>>::test_range_based_for(std::string n)
    : test(n)
{
}

bool test_range_based_for<std::array<std::string,3>>::operator()()
{
    std::array<std::string,3> container = {{
        "firststr", "secondstr", "thirdstr"}};

    int i = 0;
    for (auto it : container) {
        if (it != "firststr"
            && it != "secondstr"
            && it != "thirdstr")
            return false;
    }

    return true;
}

//
//bool test_array_rbfor()
//{
//    std::array<std::string, 3> container{"firststr", "secondstr", "thirdstr"};
//
//    int i = 0;
//    for (auto it : container)
//        if (it != "firststr"
//            && it != "secondstr"
//            && it != "thirdstr")
//            return false;
//
//    return true;
//}
//
//bool test_carray_rbfor()
//{
//    std::string container[3]{"firststr", "secondstr", "thirdstr"};
//
//    int i = 0;
//    for (auto it : container)
//        if (it != "firststr"
//            && it != "secondstr"
//            && it != "thirdstr")
//            return false;
//
//    return true;
//}
//
//bool test_string_rbfor()
//{
//    std::string container = "firststr";
//
//    int i = 0;
//    for (auto it : container)
//        if (it != 'f'
//            && it != 'i'
//            && it != 'r'
//            && it != 's'
//            && it != 't'
//            && it != 's'
//            && it != 't'
//            && it != 'r')
//            return false;
//
//    return true;
//}
