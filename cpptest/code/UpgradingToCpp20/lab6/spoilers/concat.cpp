#include "fixed_vector.hpp"
#include <cassert>
#include <iostream>

template<size_t N, size_t M>
constexpr auto concat(const fixed_vector<int,N>& a, const fixed_vector<int,M>& b)
{
    fixed_vector<int, N+M> result(a.size() + b.size());
    for (size_t i=0; i < a.size(); ++i) result[i] = a[i];
    for (size_t i=0; i < b.size(); ++i) result[a.size() + i] = b[i];
    return result;
}

int main()
{
    constexpr fixed_vector<int,2> a {5,4};
    constexpr fixed_vector<int,3> b {3,2,1};
    constexpr auto c = concat(a, b);
    static_assert(( c == fixed_vector<int,5>{ 5,4,3,2,1 } ));

    std::cout << "All tests passed!\n";
}
