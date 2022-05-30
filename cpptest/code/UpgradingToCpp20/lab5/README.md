## Lab 5: SFINAE and type-trait techniques

In this lab, you'll experiment with three different "modern C++" techniques
to dispatch at compile time between different implementations of the
same interface.

In this hypothetical scenario, some of our container types support
a getter method `bool empty() const`, and some container types
require that you manually compare `c.size() == 0`.
We are going to write a template that _abstracts away_ that API difference.

    MockVector v;
    MockList w;

    // Old ugly code
    if (v.empty()) ...
    if (w.size() == 0) ...

    // New code smooths over differences in API
    if (ourThing(v)) ...
    if (ourThing(w)) ...

In fact we're going to write three different versions of our thing,
using three different metaprogramming techniques:

- `if constexpr` (C++17)

- tag dispatch (C++03)

- overloads with SFINAE (C++03, but became easier in C++11)


### Getting started

A partial solution is present in the `partial/` directory.
You should start there.

Run `make` to build the project. It should fail spectacularly,
starting with the fact that `has_empty_method_v` does not exist yet.
Follow the instructions in main.cpp to make the unit tests pass.

If your compiler doesn't support C++17, you should still try
to implement `version_a` — but you won't be able to compile and test
your solution. Use `#if 0 / #endif` to comment out the non-working
code and its test cases.


### Bonus (C++20)

Tomorrow, Lab 7 will ask you to rewrite some of this code using Concepts.
We haven't seen the material on Concepts yet, so this bonus may be
over your head. However, if you're looking for something to do, you
might try getting a head start on Lab 7.

- Rewrite the initializer of `has_empty_method_v` to use a C++20
    _requires-expression_.

- Replace `has_empty_method_v` with `concept emptyable`.

- Make `version_c` use a C++20 constrained template alongside an
    unconstrained template (a technique called "concept overloading"),
    instead of SFINAE'ing both overloads on `enable_if_t`.

- Rewrite the condition of your `if constexpr` in `version_a`
    to use a C++20 _requires-expression_.
