CXXFLAGS= -std=c++17 -O2 -W -Wall -pedantic

test: concat perfect
	./concat
	./perfect

concat: concat.o
	$(CXX) $(CXXFLAGS) $^ -o $@

perfect: perfect.o
	$(CXX) $(CXXFLAGS) $^ -o $@

concat.o: concat.cpp fixed_vector.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

perfect.o: perfect.cpp fixed_vector.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f concat concat.o perfect perfect.o

.PHONY: clean
