TARGET=c++11_test_suite

JUNK_DIR=build

CXX = g++-4.7
CXX_OPTS = --std=c++0x -c

OBJECTS = build/main.o build/test.o build/test_suite.o build/range_based_for.o


clean :
	rm -f ${JUNK_DIR}/*.o
	rm -f ${TARGET}

all : buildCore rangeBasedFor
	@echo " "
	@echo " - build C++11 test suite."
	${CXX} ${CXX_OPTS} main.cpp -o build/main.o
	${CXX} -o ${TARGET} ${OBJECTS}
	@chmod 764 ${TARGET}

buildCore : core/test.hpp core/test_suite.hpp
	@echo " "
	${CXX} ${CXX_OPTS} core/test.cpp -o build/test.o
	${CXX} ${CXX_OPTS} core/test_suite.cpp -o build/test_suite.o

rangeBasedFor : language/range_based_for.hpp
	@echo " "
	${CXX} ${CXX_OPTS} language/range_based_for.cpp -o build/range_based_for.o
