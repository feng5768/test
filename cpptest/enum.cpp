#include <iostream>
#include <map>

using namespace std;

enum class Value : uint8_t
{
    a = 0,
    b = 1,
    c = 2
};
int main(int argc, char** argv)
{
    std::map<int, Value> m_map;
    for (int i = 0; i < 5; ++i)
    {
        m_map[i] = static_cast<Value>(i);
    }
    std::cout << "size:" << m_map.size() << std::endl;
    std::cout << "enumvalue" << static_cast<int>(m_map[0]) << std::endl;
    std::cout << "enumvalue" << static_cast<int>(m_map[1]) << std::endl;
    std::cout << "enumvalue" << static_cast<int>(m_map[2]) << std::endl;
    std::cout << "enumvalue" << static_cast<int>(m_map[3]) << std::endl;
    std::cout << "enumvalue" << static_cast<int>(m_map[4]) << std::endl;

    return 0;
}