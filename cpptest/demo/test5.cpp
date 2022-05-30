#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

using namespace std;

enum class DoorbellStatus : bool
{
    NotAllocated,
    Allocated,
};
class A
{
public:
    A(int n) : m{n}
    {
        cout << "ctor" << endl;
    }
    ~A()
    {
        cout << "dtor" << endl;
    }
    int m{5};
};

std::string alla(std::string& fileName, uint32_t lineNumber)
{
    std::string command = "dmesg | tail -n " + std::to_string(lineNumber) + " > " + fileName;
    return command;
}

struct XgmiPosition
{
    uint32_t GpuNumber{};
    uint32_t PortNumber{};
};

int main()
{
    vector<std::unique_ptr<A>> lala{};
    lala.push_back(std::make_unique<A>(5));
    std::string maybe{"/tmp/dmesg.txt"};
    std::cout << alla(maybe, 100) << std::endl;

    static std::vector<int> myArray{1, 2, 3, 4};
    for (auto& arr : myArray)
    {
        std::cout << arr << std::endl;
    }

    return 0;
}