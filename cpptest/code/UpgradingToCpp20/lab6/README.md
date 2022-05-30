## Lab 6: Fixed Vector

In this lab, you'll experiment with the kinds of changes that are
needed in order to use containers and algorithms at compile time.

In C++17, the only standard library container usable in a constexpr
context is `std::array<T,Size>`. In this lab, you've been provided with
a non-standard container named `fixed_vector<T,Capacity>`, which
supports `push_back` and `pop_back`.

There are two mini-programs in this lab.

Program 1, `concat`, tries to concatenate two `fixed_vector`s
at compile time.

Program 2, `perfect`, tries to assert some things about perfect numbers
at compile time. (Any number which is equal to the sum of all its
proper divisors is called a "perfect number." For example: 1+2+3 = 6,
or 1+2+4+7+14 = 28.)


### Getting started

A partial solution is present in the `partial/` directory.
You should start there.

Run `make` to build both mini-programs.

- `concat.cpp` will fail because `concat(a,b)` is not a constant expression.
    `concat(a,b)` is not a constant expression because `resize(n)` is not
    a constant expression. Edit `fixed_vector.hpp` to make `resize`
    appropriately constexpr-friendly.

- Then, edit `fixed_vector.hpp` to make `operator==` appropriately
    constexpr-friendly. (Unfortunately `std::equal` is not constexpr
    until C++20!)

- `perfect.cpp` will fail because `Capacity` is not a constant expression.
    Edit `perfect.cpp` to add the `constexpr` keyword in appropriate places.

- In order to make the final `static_assert` line compile, you'll have to
    make `perfects_ending_in_six` into a constexpr variable. But you also
    need to modify it! Move the for-loop into a function or
    (in C++17) a lambda-expression that returns an appropriately
    populated vector.

Notice that it is still totally possible to loop over the constexpr
data at runtime; for example, to print the numbers to `std::cout`.
Not _every_ use of a constexpr variable needs to be interpreted at compile time.


### Bonus

`perfect.cpp` also contains the line

    assert(all(perfects, are_even));

Change that runtime `assert` to a compile-time `static_assert`,
and refactor until it compiles.

In C++17, lambdas are implicitly constexpr and so `are_even` can be a lambda.
In C++14, lambdas were not constexpr. This lab exercise uses `struct IsEven`
for the benefit of students who don't have a C++17 compiler yet.
