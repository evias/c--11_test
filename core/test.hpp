/*
 * File:   test.hpp
 * Author: greg
 *
 * Created on January 6, 2013, 12:44 AM
 */

#ifndef TEST_HPP
#define	TEST_HPP

#include <string>
#include <exception>
#include <functional>
#include <memory>

namespace evias {
namespace unit_test {

    class test_exception
        : public std::exception
    {
        std::string msg_;
    public:

        test_exception(std::string);
        const char* what() const throw();
    };

    class test
    {
    protected:

        std::string name_;

    public:

        test(std::string);

        std::string getName();
        void        setName(std::string);

        /**
         * operator() method is virtual to allow
         * execution from vector<test*>::iterator
         * instance. The virtuality makes sure the
         * overloaded version of operator() is called
         **/
        virtual bool operator()();
    };

}
}


#endif	/* TEST_HPP */

