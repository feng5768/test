#include <iostream>

using namespace std;

class A
{
public:
    ~A()
    {
        std::cout << "delete" << std::endl;
    }

private:
    int m = 0;
};

class B
{
public:
    B() : i(0)
    {
        cout << "default.ctor.this:" << this << "i" << i << std::endl;
    }
    B(int j) : i(j)
    {
        cout << "ctor.this:" << this << "i" << i << std::endl;
    }
    ~B()
    {
        cout << "ctor.this:" << this << "i" << i << std::endl;
    }
    void print()
    {
        std::cout << "i" << i << std::endl;
    }

private:
    int i;
};

int main(int argc, char** argv)
{
    void* p1 = malloc(5120000);
    int*  p2 = reinterpret_cast<int*>(p1);
    for (int i = 0; i < 5120000 / sizeof(int); ++i)
    {
        if (*(p2 + i) != 0)
        {
            std::cout << "haha: " << *(p2 + i) << std::endl;
        }
    }

#ifdef _MSC_VER
    std::cout << "msc hahaha" << std::endl;
#endif

#ifdef __BORLANDC__
    std::cout << "BORLANDC hahaha" << std::endl;
#endif

#ifdef __GNUC__
    std::cout << "GNUC hahaha " << std::endl;

    void* p5 = allocator<int>().allocate(7);
    allocator<int>().deallocate((int*)p5, 7);

#endif

    void* p3        = ::operator new(512);
    int*         p4 = reinterpret_cast<int*>(p3);
    for (int i = 0; i < 512 / sizeof(int); ++i)
    {
        if (*(p4 + i) != 0)
        {
            std::cout << "haha: " << *(p4 + i) << std::endl;
        }
    }
    ::operator delete(p3);

    A* a = new A();
    // auto b = a->A();
    // delete a;

    int size = 3;
    B*  c    = new B[3];
    B*  b    = new B[3];
    B*  tmp  = b;

    for (int i = 0; i < size; ++i)
    {
        new (tmp++) B(i);
    }

    delete[] b;
    delete[] c;

    int* m  = new int[3];
    B*   bm = new (m + 1) B(5);
    bm->print();

    for (int i = 0; i < 3; ++i)
    {
        std::cout << "value:" << *(m + i) << std::endl;
    }

    delete[] m;
    return 0;
}