## Lab 1: Simple Modernizations

In this lab, you'll use C++20 features, such as `auto`,
structured bindings, and the `using` keyword,
to "modernize" a piece of C++03 code.

If your compiler doesn't support C++17, then it won't support
structured binding. However, you can still practice writing the code
and compare it against the sample solution. You will also be able to find
several improvements just using C++11 and C++14 features.


### Getting started

A partial solution is present in the `partial/` directory.
You should start there.

Run `make` to build the project. It should build, run, and pass all
its tests. However, its style is not very modern. Edit "main.cpp"
to use shorter, clearer C++17 style:

- Use ranged `for` loops.

- Use braced-initializer-lists to construct containers.

- Use `auto` placeholders for variables.

- Use `auto` return types (C++14 only).

- Use structured binding to access key-value pairs (C++17 only).

- Use `auto` in function (template) parameter lists (C++20 only).
