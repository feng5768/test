## Lab 7: Concept Overloading

In this lab, you'll refactor some C++17 templates to use concepts
instead.

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

In fact we've already written several versions of our thing,
in Lab 5. Today we're going to write one more version, using
C++20 concept overloading.


### Getting started

A partial solution is present in the `partial/` directory.
You should start there.

Run `make` to build the project. It should build and run successfully.
Follow the instructions in `main.cpp` to refactor the code
to use more C++20 features.

If your compiler doesn't support C++20, you can copy and paste the
code into https://godbolt.org/z/jWcE41KTj to test your solutions.


### Bonus: Explore the difference between Classic and Ranges

Re-open the solution for Lab 4, "Sorting Books."

Try replacing all six operators with this one declaration:

    friend std::strong_ordering operator<=>(const Book&, const Book&);

Recall that when you provide a non-defaulted `operator<=>`, the compiler
will _not_ implicitly provide a defaulted `operator==`. So, this `Book` class
has an `operator<=>` but no `operator==`.

Change `#if 0` to `#if 1`. Observe that the STL Classic version of `std::is_sorted`
compiles happily, but the Ranges version `std::ranges::is_sorted` does not
compile. The error message is _very_ long, and starts something like:

    In function 'int main()':
    main.cpp:78:34: error: no match for call to '(const std::ranges::__is_sorted_fn) (std::vector<Book>&)'
       78 |     assert(std::ranges::is_sorted(shelf));
          |            ~~~~~~~~~~~~~~~~~~~~~~^~~~~~~

In fact, we can even test and see that `std::less{}(shelf[0], shelf[1])` compiles,
but `std::ranges::less{}(shelf[0], shelf[1])` does not.

* What, mechanically, is happening here?

* Why, philosophically, does Ranges behave this way?
