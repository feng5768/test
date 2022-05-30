CXXFLAGS= -std=c++17 -O2 -W -Wall -pedantic

test: tests
	./tests

tests: main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

bonus: main-bonus.cpp
	$(CXX) $(CXXFLAGS) -std=c++20 $< -o $@

clean:
	rm -f main.o tests bonus

.PHONY: clean
