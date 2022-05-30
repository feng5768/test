#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

constexpr auto getVal()
{
    return std::array<int, 1>{3};
}

int main()
{
    constexpr auto value = getVal();
    return 1;
}