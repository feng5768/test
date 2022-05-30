#include <array>
#include <iostream>

int main()
{
    std::array data{1, 2, 3, 4, 5};

    auto total = 0;
    for (std::size_t position = 0; const auto v : data)
    {
        total += (v * position);
        position++;
    }
    std::cout << "total: " << total << std::endl;

    auto l = [] {
        return 5;
    };
    decltype(l) new_y;

    return 0;
}