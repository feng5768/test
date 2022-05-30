#include <array>
#include <bit>
#include <bitset>
#include <iostream>
#include <vector>

int log()
{
    std::cout << "heheh" << std::endl;
    return 0;
}

int main()
{
    std::vector<int> data{1, 2, 3, 4, 5};
    std::cout << data[log(), 3] << std::endl;
    return 1;
}