CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS: .hpp=.o)

all: testHeap

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* test*.o core main

testCust: testHeap.cpp customer.hpp customer.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

testHeap:$(OBJECTS) testHeap.cpp customer.hpp customer.cpp heap.hpp heap.cpp fifo.hpp fifo.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

testSim:$(OBJECTS) testSim.cpp customer.hpp customer.cpp heap.hpp heap.cpp fifo.hpp fifo.cpp sim.hpp sim.cpp statistics.hpp statistics.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^