# eVias C++11 unitary test suite

Some of the features may be buggy or their implementation may be incomplete.
This has started as a hobbie development, helping me for a faster development
of applications using C++/C++11. Bugs can be reported by mail to
<saive.gregory@gmail.com>.

This unitary test suite tests every new features proposed by the latest C++11
standards. Compilation has been tested with g++-4.7 on a Ubuntu desktop PC.

Any help in compilation instructions for other platforms, or in debugging 
execution of the test suite on any other operating system is highly appreciated.

## Requirements

* g++-4.7

## Use instructions

Compiling and linking the unitary test suite

    make all

When the compilation is done you can execute the test suite.

Executing the test suite on your platform allows you to see if you
can use all the features proposed.

To execute the unitary test suite, you execute the following
command :

    ./c--11_test/c++11_test_suite

## Contribute

I would appreciate any contributions. This project is open source and
has no limit of extension. Any kind of module or concept may be tested
by this test suite as far as it concerns newly added features of the
C++11 standard.

To contribute, you can use github.com's simple fork requests or you
can send me an email with a patch of your commit(s).

## Modules

    - Range based for-loop
      - test_range_based_for<map<string,string>>
      - test_range_based_for<vector<string>>
      - test_range_based_for<array<string,3>>
    - Move semantic
      - test_move_semantic
      - test_move_assignments  
    - Variadic templates
      - test_variadic_templates
      - addition
      - multiplication
      - dbRow variadic template class  
      - test_variadic_dbrow  
    - Initializer lists
      - test_initializer_list

