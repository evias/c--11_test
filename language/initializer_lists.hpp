/*
 * File:   initializer_lists.hpp
 * Author: greg
 *
 * Created on January 14, 2013, 10:39 AM
 */

#ifndef INITIALIZER_LISTS_HPP
#define	INITIALIZER_LISTS_HPP

#include "test.hpp"
#include <string>
#include <vector>
#include <initializer_list>

namespace evias {
namespace unit_test {

    /**
     * C++11 Features covered:
     *   - initializer_list as constructor
     *   - initializer_list as arguments
     **/
    class test_initializer_list
        : public test
    {
    protected:
        std::string name_;
    public:
        test_initializer_list(std::string);
        bool operator()() final override;
    };

    class my_object
    {
        std::vector<std::string> contents_;
    public:
        my_object(std::initializer_list<std::string>);

        void setContent(std::initializer_list<std::string>);
        std::vector<std::string> getContent() throw();
    };

    template <typename ... _types>
    class t_object
    {
        std::tuple<_types...>  contents_;
    public:
        t_object(std::tuple<_types...>);

        std::tuple<_types...> getContent() throw();
    };

}
}

#endif	/* INITIALIZER_LISTS_HPP */

