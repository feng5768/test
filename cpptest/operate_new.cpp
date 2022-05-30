#include <iostream>

using namespace std;

class A
{
public:
    ~A()
    {
        std::cout << "delete" << std::endl;
    }

    void* operator new(size_t size)
    {
        std::cout << "hahahah new:" << size << std::endl;
        return malloc(5);
    }

    void* operator new(size_t size, long aa)
    {
        std::cout << "hahahah new long:" << aa << std::endl;
        return malloc(5);
    }

    void operator delete(void* ptr)
    {
        std::cout << "hahahah delete:" << ptr << std::endl;
        free(ptr);
    }

private:
    int m = 0;
};

// inline void* operator new(size_t size)
// {
//     std::cout << "hahahah new:" << size << std::endl;
//     return malloc(5);
// }

// inline void operator delete(void* ptr)
// {
//     std::cout << "hahahah lete:" << std::endl;
//     free(ptr);
// }

int main(int argc, char** argv)
{
    int* a = new int(5);
    delete a;

    A* b = new (10) A();
    delete b;

    A d;
}