#include <iostream>
#include <list>
#include <vector>

class A
{
public:
    A(int val) : b{val}
    {
        std::cout << "ctor" << std::endl;
    }
    A(const A& a) = delete;
    // A(const A& a) : b{a.b}
    // {
    //     std::cout << "copy" << std::endl;
    // }
    A(A&&) = delete;
    // A(A&& a) : b{a.b}
    // {
    //     std::cout << "move" << std::endl;
    // }

    ~A()
    {
        std::cout << "dtor" << std::endl;
    }

    int b{};
};

int main()
{
    std::list<A> list;
    // list.reserve(5);
    for (int i = 0; i < 5; ++i)
    {
        list.emplace_back(i);
        std::cout << "hehe  " << i << std::endl;
    }
    for (auto& lis : list)
    {
        std::cout << "value: " << lis.b << std::endl;
    }

    return 0;
}