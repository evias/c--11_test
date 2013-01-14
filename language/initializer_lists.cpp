#include "initializer_lists.hpp"

using namespace evias;
using namespace unit_test;

test_initializer_list::test_initializer_list(std::string n)
    : test(n)
{
}

bool test_initializer_list::operator()()
{
    auto tuple1 = std::tuple<std::string,std::string, int, int, int>{"greg", "sophie", 27, 12, 2011};

    auto obj1 = new my_object{"greg", "sophie", "evias", "soo"};
    auto obj2 = new t_object<std::string,std::string, int, int, int>(tuple1);

    if (obj1->getContent().at(0) != "greg"
        || obj1->getContent().at(1) != "sophie"
        || obj1->getContent().at(2) != "evias"
        || obj1->getContent().at(3) != "soo")
        return false;

    if (std::get<0>(obj2->getContent()) != "greg"
        || std::get<1>(obj2->getContent()) != "sophie"
        || std::get<2>(obj2->getContent()) != 27
        || std::get<3>(obj2->getContent()) != 12
        || std::get<4>(obj2->getContent()) != 2011)
        return false;

    delete obj1;
    delete obj2;

    return true;
}

/* Example class */

my_object::my_object(std::initializer_list<std::string> list)
    : contents_(list)
{
}

void my_object::setContent(std::initializer_list<std::string> list)
{
    contents_ = list;
}

std::vector<std::string> my_object::getContent()
    throw()
{
    return contents_;
}

/* More complex example class */
template <typename ... _types>
t_object<_types...>::t_object(std::tuple<_types...> list)
    : contents_(list)
{
}

template <typename ... _types>
std::tuple<_types...> t_object<_types...>::getContent()
    throw()
{
    return contents_;
}