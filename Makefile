TARGET=c++11_test_suite

JUNK_DIR=build

CXX = g++-4.7
CXX_OPTS = --std=c++0x -Icore/ -c

CORE = build/main.o \
       build/test.o \
       build/test_suite.o

LANGUAGE = build/range_based_for.o \
	   build/move_semantic_only.o \
	   build/variadic_templates.o \
	   build/variadic_dbrow.o \
	   build/initializer_lists.o

# Makefile rules
clean :
	rm -f ${JUNK_DIR}/*.o
	rm -f ${TARGET}

all : buildCore buildLanguageTests
	@echo " "
	@echo " - build C++11 test suite."
	${CXX} ${CXX_OPTS} main.cpp -o build/main.o
	${CXX} -o ${TARGET} ${CORE} ${LANGUAGE}
	@chmod 764 ${TARGET}

buildCore : core/test.hpp core/test_suite.hpp
	@echo " "
	${CXX} ${CXX_OPTS} core/test.cpp -o build/test.o
	${CXX} ${CXX_OPTS} core/test_suite.cpp -o build/test_suite.o

buildLanguageTests : language/range_based_for.hpp language/move_semantic_only.hpp language/variadic_templates.hpp language/variadic_dbrow.hpp language/initializer_lists.hpp
	@echo " "
	${CXX} ${CXX_OPTS} language/range_based_for.cpp -o build/range_based_for.o
	${CXX} ${CXX_OPTS} language/move_semantic_only.cpp -o build/move_semantic_only.o
	${CXX} ${CXX_OPTS} language/variadic_templates.cpp -o build/variadic_templates.o
	${CXX} ${CXX_OPTS} language/variadic_dbrow.cpp -o build/variadic_dbrow.o
	${CXX} ${CXX_OPTS} language/initializer_lists.cpp -o build/initializer_lists.o
