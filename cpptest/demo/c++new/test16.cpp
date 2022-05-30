#include <array>
#include <concepts>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

struct Reg1
{
    static constexpr int a = 5;
};

struct Reg2
{
    static constexpr int a = 6;
};

class Base
{
};

template<typename REG>
class ver1 : public Base
{
public:
    void print()
    {
        std::cout << "lala: " << REG::a << std::endl;
    }
};

template<typename REG>
class ver2 : public Base
{
public:
    void print()
    {
        std::cout << "hehe: " << REG::a << std::endl;
    }
};

template<class REG, template<class> class VER>
requires std::derived_from<VER<REG>, Base> && std::derived_from<VER<REG>, Base>
class engine
{
public:
    void outPut()
    {
        m_ver.print();
    }

private:
    VER<REG> m_ver{};
};

namespace a
{
class aa
{
};
namespace b
{
class aa : public a::aa
{
};
}  // namespace b
}  // namespace a

int main()
{
    ver1<Reg2> ver{};
    ver.print();
    engine<Reg2, ver2> eng{};
    eng.outPut();
    return 0;
}