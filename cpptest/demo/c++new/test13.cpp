#include <iostream>
#include <span>
#include <vector>

using namespace std;

class A
{
public:
    vector<int> item()
    {
        return {1, 2, 3};
    }

protected:
    int mmm{10};
};

struct XgmiPosition
{
    uint32_t GpuNumber{};
    uint32_t PortNumber{};
};

A foo()
{
    return A{};
}

int main()
{
    cout << "hello" << endl;
    for (auto& m : foo().item())
    {
        cout << m << endl;
    }
    std::vector<XgmiPosition> posi(10);
    for (auto m : posi)
    {
        std::cout << "hehe" << m.GpuNumber << " " << m.PortNumber << std::endl;
    }
    A a{};
    std::cout << a.mmm << std::endl;

    return 0;
}