#include <iostream>
#include <type_traits>

template<typename T>
concept myfloat = std::is_floating_point_v<T>;

auto go(const myfloat auto a, const myfloat auto b)
{
    return a + b;
}

int main()
{
    myfloat auto const val = go(1.3, 2.5);
    std::cout << "" << val << std::endl;
    std::cout << "" << go(1.2, 2.3f) << std::endl;
    puts("hehe");
    return 1;
}