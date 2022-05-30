#include <iostream>
using namespace std;
template<class T>
T foo(T t)
{
    return t + 1;
}
// more constrained:
// template<class T>
// concept Integral_signed = is_integral_v<T>&& is_signed_v<T>;
// template<class T>
// concept Scalar = is_scalar_v<T>;
// template<class T>
// concept Integral = Scalar<T>&& is_integral_v<T>;
// template<class T>
// concept Floating = Scalar<T>&& is_floating_point_v<T>;

template<class T>
concept Integral = is_integral_v<T>;

template<class T>
concept Integral_unsigned = Integral<T>&& is_unsigned_v<T>;

// Why???Why???Why???Why???Why???Why???Why???Why???Why???Why???Why???Why???Why???Why???Why???Why???
// template<class T> void foo(T) requires Scalar<T>;
//  // ...is subsumed by the more constrained template...
// template<class T> void foo(T) requires Integral<T>;

// template<class T> void foo(T) requires !Integral<T>;
//  // ...has no subsumption relationship at all with...
// template<class T> void foo(T) requires !Scalar<T>;
template<class T>
requires(!Integral_unsigned<T>) T foo(T t)
{
    return t + 2;
}
template<class T>
requires(!Integral<T>) T foo(T t)
{
    return t + 3;
}
int main()
{
    double a = 0.0;
    // int  a   = 0;
    auto val = foo(a);
    cout << "val: " << val << endl;
    cout << "done." << endl;
    return 0;
}
