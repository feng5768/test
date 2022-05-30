#include "fixed_vector.hpp"
#include <cassert>
#include <iostream>

bool is_perfect(int n) {
    int sum_of_proper_factors = 1;
    for (int i=2; i*i < n; ++i) {
        if (n % i == 0) {
            sum_of_proper_factors += i + (n / i);
            if (sum_of_proper_factors > n)
                return false;
        }
    }
    return (sum_of_proper_factors == n);
}

auto perfects_less_than(int n) {
    fixed_vector<int, 10> v;
    for (int i=2; i < n; ++i)
        if (is_perfect(i))
            v.push_back(i);
    return v;
}

template<class Ctr, class Pred>
bool all(const Ctr& c, Pred pred) {
    for (const auto& elt : c)
        if (!pred(elt))
            return false;
    return true;
}

struct IsEven {
    bool operator()(int x) const { return x % 2 == 0; }
};

int main() {
    auto perfects = perfects_less_than(1000);

    for (int i : perfects) {
        std::cout << i << '\n';
    }

    auto are_even = IsEven();
    assert(all(perfects, are_even));

    size_t Capacity = perfects.size();
    using FVector = fixed_vector<int, Capacity>;

    FVector perfects_ending_in_six;
    for (int i : perfects) {
        if (i % 10 == 6) {
            perfects_ending_in_six.push_back(i);
        }
    }

    static_assert(( perfects_ending_in_six == FVector{6, 496} ));

    std::cout << "All tests passed!\n";
}
