#include <iostream>
#include <set>

struct Data
{
    int  i;
    int  j;
    auto operator<=>(const Data&) const = default;
    // bool operator<(const Data& d) const
    // {
    //     return ((i < d.i) || ((i == d.i && j < d.j)));
    // }
};

int main()
{
    std::set<Data> m_set{};
    m_set.insert(Data{3, 2});
    m_set.insert(Data{1, 3});
    m_set.insert(Data{2, 2});

    for (const auto& m : m_set)
    {
        std::cout << m.i << " " << m.j << std::endl;
    }
    return 1;
}