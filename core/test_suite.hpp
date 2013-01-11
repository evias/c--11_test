/*
 * File:   test_suite.hpp
 * Author: greg
 *
 * Created on January 6, 2013, 12:42 AM
 */

#ifndef TEST_SUITE_HPP
#define	TEST_SUITE_HPP

#include "test.hpp"

#include <initializer_list>
#include <string>
#include <vector>

namespace evias {
namespace unit_test {

    enum message_t {
        INFO = 0,
        ERROR
    };

    class suite
    {
        std::vector<test*>   tests_;
        std::vector<suite*>  suites_;

        std::string name_;

    public :

        suite(std::string);
        suite(std::string, std::initializer_list<test*>);

        bool run();
        void print(std::string, message_t);

        std::string getName() throw();
        void setName(std::string) throw();
        void addSuite(suite*);

    private:
        bool run_tests();
    };

}
}

#endif	/* TEST_SUITE_HPP */

