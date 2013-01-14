#include "variadic_dbrow.hpp"
#include "variadic_templates.hpp"

using namespace evias;
using namespace unit_test;

template <typename ... _fields_types>
dbRow<_fields_types...>::dbRow(std::string relation, std::string pkey, std::tuple<_fields_types...> values)
    : relation_(relation),
      pkey_(pkey),
      values_(values)
{
}

template <typename ... _fields_types>
std::string dbRow<_fields_types...>::getRelation()
    throw()
{
    return relation_;
}

template <typename ... _fields_types>
std::string dbRow<_fields_types...>::getPKey()
    throw()
{
    return pkey_;
}

template <typename ... _fields_types>
std::tuple<_fields_types...> dbRow<_fields_types...>::getValues()
    throw()
{
    return values_;
}

/* Template specialization */

dbRow<int,int>::dbRow(std::tuple<int,int> values)
    : values_(values)
{
    fstid_ = std::get<0>(values_);
    sndid_ = std::get<1>(values_);
}

int dbRow<int,int>::getFirstID()
    throw()
{
    return fstid_;
}

int dbRow<int,int>::getSecondID()
    throw()
{
    return sndid_;
}

/* Unitary test implementation */
test_variadic_dbrow::test_variadic_dbrow(std::string n)
    : test(n)
{
}

bool test_variadic_dbrow::operator()()
{
    /* Prepare rows data */
    auto val1 = std::tuple<int, std::string, std::string>{1, "boost", "Wt"};
    auto val2 = std::tuple<std::string, std::string, std::string>{"greg@evias.be", "Greg", "Saive"};

    /* Instantiate rows */
    auto row1 = new dbRow<int,std::string,std::string>("table1", "pkey1", val1);
    auto row2 = new dbRow<std::string,std::string,std::string>("table2", "pkey2", val2);
    auto row3 = new dbRow<int,int>(std::tuple<int,int>{1, 2});

    /* Check data */
    if (std::get<0>(row1->getValues()) != 1
        || std::get<1>(row1->getValues()) != "boost"
        || std::get<2>(row1->getValues()) != "Wt")
        return false;

    if (std::get<0>(row2->getValues()) != "greg@evias.be"
        || std::get<1>(row2->getValues()) != "Greg"
        || std::get<2>(row2->getValues()) != "Saive")
        return false;

    if (row3->getFirstID() != 1 || row3->getSecondID() != 2)
        return false;

    delete row1;
    delete row2;
    delete row3;

    return true;
}