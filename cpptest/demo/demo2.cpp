#include <iostream>

using namespace std;

template<class T>
T foo(T t)
{
    return t + 1;
}
// NOT more constrained:
// template<class T> requires is_integral_v<T>
// T foo(T t)
// {
//     return t+2;
// }
// template<class T> requires (sizeof(T) == 4)
// T foo(T t)
// {
//     return t+3;
// }
// template<class T> requires (sizeof(T) != 0)
// T foo(T t)
// {
//     return t+4;
// }
// NOT more constrained:
// template<class T>
// T foo(T t) requires is_integral_v<T>
// {
//     return t + 2;
// }
// template<class T>
// T foo(T t) requires is_integral_v<T>&& is_signed_v<T>
// {
//     return t + 3;
// }

// interface/tng/cmn/types/composable_interface.h:41
// actually:
// template<class T>
// T foo(T t) requires true
// {
//     return t + 2;
// }
// template<class T>
// T foo(T t) requires false
// {
//     return t + 2;
// }

// more constrained:
template<class T>
concept Integral = is_integral_v<T>;

template<class T>
T foo(T t) requires Integral<T>
{
    return t + 2;
}
template<class T>
T foo(T t) requires Integral<T>&& is_signed_v<T>
{
    return t + 3;
}

int main()
{
    auto val = foo(0);
    cout << "val: " << val << endl;
    cout << "done." << endl;
    return 0;
}