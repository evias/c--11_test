/*
 * File:   classes_definitions.hpp
 * Author: greg
 *
 * Created on January 11, 2013, 4:29 PM
 */

#ifndef MOVE_SEMANTIC_ONLY_HPP
#define	MOVE_SEMANTIC_ONLY_HPP

#include "../core/test.hpp"
#include <algorithm>
#include <string>

namespace evias {
namespace unit_test {

    class test_move_semantic
        : public test
    {
        int content_;
    protected :
        std::string name_;

    public:
        test_move_semantic(std::string);
        test_move_semantic(test_move_semantic&&);
        test_move_semantic& operator=(test_move_semantic&&);
        void                setContent(int) throw();
        bool                operator()();

        /**
         * Copy constructor and copy assignment operator
         * are deleted as this class needs to accept
         * only move semantic.
         */
        test_move_semantic(const test_move_semantic&) = delete;
        test_move_semantic& operator=(const test_move_semantic&) = delete;

    };

}
}

#endif	/* MOVE_SEMANTIC_ONLY_HPP */

