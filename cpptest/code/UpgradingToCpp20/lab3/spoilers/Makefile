CXXFLAGS= -std=c++17 -O2 -W -Wall -pedantic

test: tests
	./tests

tests: main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp clone_ptr.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

fold: fold.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f main.o tests fold.o fold

.PHONY: clean
