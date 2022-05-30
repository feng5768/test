#include <array>
#include <iostream>
#include <vector>

struct Base
{
    constexpr virtual int getValue() const = 0;
};

struct Derived1 : Base
{
    constexpr int getValue() const override
    {
        return 5;
    }
};

struct Derived2 : Base
{
    constexpr int getValue() const override
    {
        return 10;
    }
};

constexpr auto getSomeValue()
{
    const Derived1                   d1;
    const Derived1                   d2;
    const Derived1                   d3;
    const Derived2                   d4;
    const Derived2                   d5;
    const std::array<const Base*, 5> data{&d1, &d2, &d3, &d4, &d5};

    int sum = 0;
    for (const auto* elem : data)
    {
        sum += elem->getValue();
    }
    return sum;
}

int main()
{
    constexpr auto m = getSomeValue();
    std::cout << "value :" << m << std::endl;

    return 0;
}