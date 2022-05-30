## Lab 3: Perfect Forwarding

This lab provides you with a non-standard "smart pointer" called
`ClonePtr`. When a `ClonePtr` is destroyed, it deallocates the
heap-allocated object to which it points. When it's moved, it
transfers ownership. But when it's _copied_, it calls `obj->clone()`
to obtain a pointer to a new heap-allocated object, which it
places into the destination of the copy. None of this is terribly
relevant to Lab 3, honestly!

In this lab, you'll extend the provided `ClonePtr` with a
variadic perfect-forwarding `make_clone` template, just like
`make_unique` and `make_shared`.

    ClonePtr<X> a = make_clone<X>(42);
    ClonePtr<String> a = make_clone<String>("abc");
    ClonePtr<String> b = make_clone<String>("abcdef", 3);
    ClonePtr<String> c = make_clone<String>(10, 'x');


### Getting started

A partial solution is present in the `partial/` directory.
You should start there.

Run `make` to build the project. The compiler will complain
that `make_clone<Sheep>` was called with zero arguments instead
of the expected 1 argument.

Rewrite `make_clone` in "clone_ptr.hpp" so that it accepts
any number of parameters and perfectly forwards them to the
controlled object's constructor.


### Bonus: Investigate fold-expressions

In the `spoilers/` directory, you'll find a file named "fold.cpp".
Read its code, then compile and run it.

Are the results as you expected?


### Second bonus: Investigate `ClonePtr`

Read the code of `clone_ptr.hpp` from top to bottom. Does it
make sense? Do you see any C++ syntax that you don't recognize?
Please feel free to ask questions, either during the lab or afterward.
