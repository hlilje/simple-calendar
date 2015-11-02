CXX = g++-4.9
CFLAGS = -g -Wall -std=c++11
LIBS = ../cxxtest
TARGET = calendar
TEST_TARGET = test

.PHONY: default all clean test

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CFLAGS) -c $< -o $@ -I$(LIBS)

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -Wall -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
	-rm -f $(TEST_TARGET)
	-rm -f testrunner.cpp
	-rm -f *.out
	-rm -r -f *.dSYM

test_init:
	python2 $(LIBS)/cxxtestgen.py --error-printer \
	-o testrunner.cpp test_calendar.cpp

test: test_init $(OBJECTS)
	$(CXX) $(CFLAGS) -o $(TEST_TARGET) -I$(LIBS) \
	testrunner.cpp $(OBJECTS)
