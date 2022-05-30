#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

class A
{
public:
    /**
     *
     * @param val
     */
    A(int val) : b{val}
    {
        std::cout << "ctor" << std::endl;
    }
    // A(const A& a) = delete;
    A(const A& a) : b{a.b}
    {
        std::cout << "copy" << std::endl;
    }
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
    std::vector<int> arr{1, 2, 3, 4};
    static_assert(arr.size());
    return 0;
}