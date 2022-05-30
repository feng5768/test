#include <algorithm>
#include <iostream>

constexpr auto sort(auto data)
{
    std::sort(begin(data), end(data));
    return data;
}

int main()
{
    constexpr auto sortedData = sort(std::array{3, 2, -1, 5, 6});
    static_assert(std::is_sorted(begin(sortedData), end(sortedData)));
    std::cout << " hhe" << sortedData[0] << std::endl;
    return 1;
}