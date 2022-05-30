#include <iostream>
#include <utility>

template<typename Callable, typename... Param>
auto bind_values(Callable call, Param... par)
{
    return [callable = std::move(call), ... myParam = std::move(par)]() {
        return callable(myParam...);
    };
}

int add(int a, int b)
{
    return a + b;
}

int main()
{
    const auto bound = bind_values(add, 3, 4);
    std::cout << "value :" << bound() << std::endl;
    return 1;
}