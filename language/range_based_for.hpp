/*
 * File:   range_based_for.hpp
 * Author: greg
 *
 * Created on January 5, 2013, 5:52 PM
 */

#ifndef RANGE_BASED_FOR_HPP
#define	RANGE_BASED_FOR_HPP

#include "../core/test.hpp"
#include <vector>
#include <map>
#include <array>
#include <string>
#include <memory>
#include <functional>

namespace evias {
namespace unit_test {

    /**
     * Base template class for test_range_based_for
     * unitary tests.
     *
     * This class is declared as final as no other
     * unitary test will overload functionalities of it.
     *
     * C++11 Features covered:
     *  - auto
     *  - range based for-loop with map<int,string>
     *  - range based for-loop with vector<string>
     *  - range based for-loop with array<string,3>
     **/

    template <typename container_t>
    class test_range_based_for final : public test {};

    /**
     * Class template specialization
     *
     * test_range_based_for<map<string,string>>
     */
    template <>
    class test_range_based_for<std::map<int,std::string>> final
        : public test
    {
    protected:
        std::string name_;

    public :
        test_range_based_for(std::string);
        bool operator()() final override;
    };

    /**
     * Class template specialization
     *
     * test_range_based_for<vector<string>>
     */
    template <>
    class test_range_based_for<std::vector<std::string>> final
        : public test
    {
    protected:
        std::string name_;

    public:
        test_range_based_for(std::string);
        bool operator()() final override;
    };

    /**
     * Class template specialization
     *
     * test_range_based_for<vector<string>>
     */
    template <>
    class test_range_based_for<std::array<std::string,3>> final
        : public test
    {
    protected:
        std::string name_;

    public:
        test_range_based_for(std::string);
        bool operator()() final override;
    };

    /**
     * XXX test_range_based_for<string[]>
     * XXX test_range_based_for<string>
     **/

}
}

#endif	/* RANGE_BASED_FOR_HPP */

