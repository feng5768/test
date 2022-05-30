#include <algorithm>
#include <array>
#include <iostream>
#include <list>
#include <vector>

void remove5(auto& vec)
{
    std::erase_if(vec, [](const auto& la) {
        return (la == 5);
    });
}

int main()
{
    std::vector<int> a{1, 2, 3, 4, 5, 6, 3, 4, 5, 7};
    remove5(a);
    for (const auto& m : a)
    {
        std::cout << m << " ";
    }
    std::cout << std::endl;
}