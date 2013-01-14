/*
 * File:   variadic_dbrow.hpp
 * Author: greg
 *
 * Created on January 13, 2013, 10:01 PM
 */

#ifndef VARIADIC_DBROW_HPP
#define	VARIADIC_DBROW_HPP

#include "test.hpp"
#include <string>
#include <tuple>

namespace evias {
namespace unit_test {

    /**
     * Variadic template class for storing database rows.
     *
     * Example based on variadic template std::tuple class.
     *
     * C++11 Features covered:
     *   - Variadic templates
     *   - Parameter packs
     *
     **/

    /**
     * Unitary test entry
     **/
    class test_variadic_dbrow
        : public test
    {
    protected:
        std::string name_;
    public:
        test_variadic_dbrow(std::string);
        bool operator()() final override;
    };

    /* Variadic template class */
    template <typename ... _fields_types>
    class dbRow
    {
        std::string relation_;
        std::string pkey_;

        std::tuple<_fields_types...> values_;
    public:
        dbRow(std::string, std::string, std::tuple<_fields_types...>);

        std::string getRelation() throw();
        std::string getPKey() throw();

        std::tuple<_fields_types...> getValues() throw();
    };

    /**
     * Specializing a dbRow to a specific database
     * relation row model. This specialization proposes
     * methods for a simple and useful relationship row.
     *
     * This template specialization can be used to work
     * effectively with 1 to 1 database relations.
     */

    template<>
    class dbRow<int, int>
    {
        int fstid_;
        int sndid_;

        std::tuple<int,int> values_;
    public:
        dbRow(std::tuple<int, int>);

        int getFirstID() throw();
        int getSecondID() throw();
    };

}
}

#endif	/* VARIADIC_DBROW_HPP */

