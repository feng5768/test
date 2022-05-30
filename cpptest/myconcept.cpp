#include <iostream>
using namespace std;

template<class T>
T foo(T t)
{
    return t + 1;
}

// more constrained:
template<class T>
concept Integral_signed = is_integral_v<T>&& is_signed_v<T>;

template<class T>
concept Scalar = is_scalar_v<T>;

template<class T>
concept Integral = Scalar<T>&& is_integral_v<T>;

template<class T>
concept Floating = Scalar<T>&& is_floating_point_v<T>;

// emplate<class T> void foo(T) requires Scalar<T>;
//  // ...is subsumed by the more constrained template...
// template<class T> void foo(T) requires Integral<T>;
// template<class T> void foo(T) requires !Integral<T>;
//  // ...has no subsumption relationship at all with...
// template<class T> void foo(T) requires !Scalar<T>;

template<class T>
requires(!Integral<T>) T foo(T t)
{
    return t + 2;
}

template<class T>
requires(!Scalar<T>) T foo(T t)
{
    return t + 3;
}

int main()
{
    auto val = foo(0.0);
    cout << "val: " << val << endl;
    cout << "done." << endl;
    return 0;
}

// noexcept VS clause
// 1 noexcept
// we have both

// clang-format off
# noexcept VS requires
    # We have both expression and clause:
        # For noexcept:
          ==>clause:
            void fun() noexcept(expression);
          ==>expression:
            constexpr bool val = noexcept(expression);

        # For requires:
          ==>clause:
            void fun() requires(expression);
          ==>expression:
            constexpr bool val = requires(parameter-list){requirement-seq};

        # Noexcept-clause contains a noexcept-expression:
            template<class T>
            void fun() noexcept(noexcept(expression));
            ==
            template<class T>
            constexpr bool val = noexcept(expression);

            template<class T>
            void fun() noexcept(val<T>);
        # Requires-clause contains a requires-expression:
            template<class T>
            void fun() requires( requires(parameter-list){requirement-seq} ){};
            ==
            template<class T>
            concept val = requires(parameter-list){requirement-seq};

            template<class T>
            void fun() requires val<T>{};
// clang-format on
