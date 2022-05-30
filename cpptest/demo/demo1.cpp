// clang-format off
// ##concept
//     ##目的： 对SFINEA的改进，从而使代码变得更易读，容错率更低。

// clang-format on

#include <iostream>
using namespace std;
class A
{
public:
    using intType = int;
    intType fun1(intType b)
    {
        a = b;
        return a;
    }
    static intType fun2()
    {
        return 42;
    }
    int fun3()
    {
        return 42;
    }

private:
    intType a{};
};
// 1
// old style
// interface/tng/cmn/types/attributes.h:69
template<class T, class = void>
struct is_TypeA : false_type
{
};
template<class T>
struct is_TypeA<T, void_t<typename T::intType, decltype(T::fun2())>> : true_type
{
};
// new:  engine/oss/sdma/include/ip/oss/sdma/packet/sdma_packet_types.h:112
template<class T>
concept TypeA = requires(T t, T::intType& val)
{
    typename T::intType;
    {t.fun1(val)};
    {t.fun2()};
};

// old: engine/oss/sdma/test/monolithic/sdma_queue_test.cpp:112
template<class TypeA, class = enable_if_t<is_TypeA<TypeA>::value>>
void myPrint(TypeA a)
{
    cout << a.fun3() << endl;
    cout << "is TyeA" << endl;
}
// clang-format off

// new
// version1
template<class T> requires TypeA<T>
void myPrint_new(T t)
{
    cout<<t.fun3()<<endl;
    cout<<"is TyeA new"<<endl;
}
// version2
template<class T>
requires TypeA<T>
void myPrint_new(T t)
{
    cout<<t.fun3()<<endl;
    cout<<"is TyeA new"<<endl;
}
// version3
template<TypeA T>
void myPrint_new(T t)
{
    cout << t.fun3() << endl;
    cout << "is TyeA new" << endl;
}
// version4
void myPrint_new(TypeA auto t)
{
    cout<<t.fun3()<<endl;
    cout<<"is TyeA new"<<endl;
}
// clang-format on

int main()
{
    // 1
    static_assert(is_TypeA<A>::value);     // A is type A
    static_assert(!is_TypeA<int>::value);  // int is not type A
    static_assert(TypeA<A>);               // A is type A
    static_assert(!TypeA<int>);            // int is not type A

    // 2
    cout << "log begin:" << endl;
    myPrint<A>();
    // this is not the result what we want!
    myPrint<int, int>();

    A a;
    myPrint_new<A>(a);
    myPrint_new(a);
    cout << "done." << endl;
    return 0;
}