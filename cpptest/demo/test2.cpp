#include <iostream>

using namespace std;

class intType
{
public:
    int a = 1;
};
class DoubleType
{
public:
    double a = 1.1;
};

template<class T>
concept TypeInt = requires(T t)
{
    typename T::intType;
};

template<class T>
concept TypeDouble = requires(T t)
{
    typename T::DoubleType;
};

template<class T>
requires TypeInt<T> class M
{
};

template<class T>
requires TypeDouble<T> class M
{
};

class A : public M<A>
{
public:
    intType a{};
};

// class B : public M<B>
// {
// public:
//     DoubleType b{};
// };

int main()
{
    A a;
    // B b;
    return 0;
}