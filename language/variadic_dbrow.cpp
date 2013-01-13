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
    auto val1_1 = std::tuple<int, std::string, std::string>{1, "boost", "Wt"};
    auto val1_2 = std::tuple<int, std::string, std::string>{2, "Zend Framework", "CakePHP"};
    auto val1_3 = std::tuple<int, std::string, std::string>{3, "Qt", "pqxx"};

    auto val2_1 = std::tuple<std::string, std::string, std::string>{"greg@evias.be", "Greg", "Saive"};
    auto val2_2 = std::tuple<std::string, std::string, std::string>{"so@evias.be", "Sophie", "TuSaurasPas"};
    auto val2_3 = std::tuple<std::string, std::string, std::string>{"gregso@evias.be", "Greg", "Sophie"};

    auto row1_1 = new dbRow<int,std::string,std::string>("table1", "pkey1", val1_1);
    auto row1_2 = new dbRow<int,std::string,std::string>("table1", "pkey1", val1_2);
    auto row1_3 = new dbRow<int,std::string,std::string>("table1", "pkey1", val1_3);

    auto row2_1 = new dbRow<std::string,std::string,std::string>("table2", "pkey2", val2_1);
    auto row2_2 = new dbRow<std::string,std::string,std::string>("table2", "pkey2", val2_2);
    auto row2_3 = new dbRow<std::string,std::string,std::string>("table2", "pkey2", val2_3);

    if (std::get<1>(row1_1->getValues()) != "boost")
        return false;

    if (std::get<1>(row2_2->getValues()) != "Sophie")
        return false;

    if (std::get<0>(row1_3->getValues()) != 3)
        return false;

    if (row1_1->getRelation() != "table1")
        return false;

    delete row1_1;
    delete row1_2;
    delete row1_3;
    delete row2_1;
    delete row2_2;
    delete row2_3;

    return true;
}
