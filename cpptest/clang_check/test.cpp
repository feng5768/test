#include <algorithm>
#include <iostream>
#include <set>
#include <span>
#include <vector>

using namespace std;

struct ResourceType
{
    uint32_t m_gpuNumber{};

protected:
    ResourceType(uint32_t num) : m_gpuNumber{num} {};
};

struct GeneralType : public ResourceType
{
    GeneralType(uint32_t number) : ResourceType{number} {};
    std::string name{"general"};
    uint32_t    m_general = 0;
};

struct AidType : public ResourceType
{
    uint32_t    m_AidNumber;
    std::string name{"aid"};

    AidType(uint32_t a, uint32_t b) : ResourceType(a), m_AidNumber{b} {};
};

class A
{
    // template<class T>
    // void print(T t)
    // {
    //     if constexpr (std::is_same<T, GeneralType>::value)
    //     {
    //         std::cout << t.m_general << std::endl;
    //     }
    //     else
    //     {
    //         std::cout << t.m_AidNumber << std::endl;
    //     }
    // }

    void printA(AidType t)
    {
        std::cout << t.m_AidNumber << std::endl;
    }
    void printA(GeneralType t)
    {
        std::cout << t.m_general << std::endl;
    }

public:
    void mmain()
    {
        AidType     a{1, 2};
        GeneralType b{1};
        // print(a);
        printA(a);
        // print(b);
    }

    template<class T>
    void dma(T resource)
    {
        if (std::is_same<T, GeneralType>::value)
        {
            cout << "general" << endl;
        }
        else
        {
            cout << "aid" << endl;
        }
    }
};

int main()
{
    cout << "test begin" << endl;
    AidType                  b{1, 2};
    GeneralType              c{1};
    std::vector<AidType>     vector{{1, 2}, {3, 4}};
    std::vector<GeneralType> vector1{1, 2};
    A                        a;
    a.mmain();
    a.dma(b);
    a.dma(c);

    return 0;
}