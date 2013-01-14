/*
 * File:   variadic_templates.hpp
 * Author: greg
 *
 * Created on January 11, 2013, 8:36 PM
 */

#ifndef VARIADIC_TEMPLATES_HPP
#define	VARIADIC_TEMPLATES_HPP

#include "test.hpp"
#include <string>

namespace evias {
namespace unit_test {

    /**
     * C++11 Features covered:
     *  - Variadic templates
     **/

    class test_variadic_templates
        : public test
    {
    protected:
        std::string name_;

    public:
        test_variadic_templates(std::string);
        bool operator()() final override;
    };

    template <int ...> struct addition;
    template <int ...> struct multiplication;

    /**
     * Specializations for empty template list.
     * These specializations specify the neutral
     * element of the specialized operator.
     **/

    template <>
    struct addition<>
    {
        constexpr static const int value = 0;
    };

    template <>
    struct multiplication<>
    {
        constexpr static const int value = 1;
    };

    /**
     * Specializations for the actual template calculation.
     * These class specialization work recursively. This allows
     * having the sum/substraction/multiplication/division result
     * ready at compile time already.
     */

    template <int fst, int ... rest>
    struct addition<fst, rest...>
    {
        /* This line represents the whole magic of this compile-time
         * template calculator. It works recursively to retrieve the
         * sum of the 'rest' template arguments. (next round -1 argument) */
        constexpr static const int value = fst + addition<rest...>::value;
    };

    template <int fst, int ... rest>
    struct multiplication<fst, rest...>
    {
        constexpr static const int value = fst * multiplication<rest...>::value;
    };

}
}

#endif	/* VARIADIC_TEMPLATES_HPP */

