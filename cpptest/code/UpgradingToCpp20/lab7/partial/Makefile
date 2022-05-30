CXXFLAGS= -std=c++20 -O2 -W -Wall -pedantic

test: tests
	./tests

tests: main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f main.o tests

.PHONY: clean
