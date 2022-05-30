#include <iostream>
#include <span>
#include <vector>

using namespace std;
class Test
{
public:
    std::span<const int> get()
    {
        return data;
    }

    std::vector<int> data{1, 2, 3, 4, 5};
};

int main()
{
    std::vector<int> data{};
    data.resize(10, 0);
    int la = 5;
    for (auto& m : data)
    {
        m = ++la;
    }
    for (auto& m : data)
    {
        cout << m << " ";
    }
    cout << std::endl;
    std::vector<int> mdata{1};
    mdata = data;
    for (auto& m : mdata)
    {
        cout << m << " ";
    }
}