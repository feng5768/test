#include <algorithm>
#include <iostream>

using namespace std;

bool compare(uint8_t m, uint32_t n)
{
    return false;
}

int main()
{
    vector<uint8_t>        a{1, 2, 3};
    const vector<uint32_t> b{1, 2, 3};
    uint8_t                c = 5;
    uint8_t                d = 6;

    if (std::ranges::equal(a, b))
    {
        cout << "hehe" << endl;
    }
    if (std::ranges::equal(c, d))
    {
        cout << "hehe" << endl;
    }
    return 0;
}