CXXFLAGS= -std=c++17 -O2 -W -Wall -Wextra -pedantic

test: tests
	./tests

tests: main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f tests main.o

.PHONY: clean
