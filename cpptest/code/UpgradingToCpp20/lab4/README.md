## Lab 4: Sorting Books

In this lab, you'll update a C++11 class to use C++20 features
for its comparison operators.

It is highly likely that your compiler doesn't support enough of
C++20 to compile this lab. However, you can copy and paste the code
into https://godbolt.org/z/jWcE41KTj to test your solutions.


### Getting started

A partial solution is present in the `partial/` directory.
You should start there.

Run `make` to build the project. It should build, run, and pass all
its tests. The way it's written now is perfectly valid C++20 and there
is nothing wrong with it! However, if we are working in C++20, then
we can simplify the code for `Book`'s comparison operators, to accomplish
the same effects with much less code. Edit "main.cpp"
to use shorter, clearer C++20 style.
