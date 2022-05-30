#include <cassert>
#include <cstdio>
#include <type_traits>
#include <vector>


// has_empty_method<C> is an STL-style type trait template.

template<class C, class = void>
struct has_empty_method : std::false_type {};

template<class U>  // partial specialization
struct has_empty_method<U, decltype(std::declval<const U&>().empty(), void())> : std::true_type {};


// Your first job is to implement these two wrappers:
// - has_empty_method_t<C>: this type should be true_type or false_type
// - has_empty_method_v<C>: this value should be true or false

// _t version: this should be an alias template
// YOUR CODE GOES HERE

// _v version: this should be a (bool) variable template
// YOUR CODE GOES HERE


// Verify that your implementation passes the following unit tests.

struct MockVector {
    int size_ = 0;
    bool empty() const { return size_ == 0; }
};
struct MockList {
    int size_ = 0;
    int size() const { return size_; }
};

static_assert(has_empty_method<MockVector>::value, "");
static_assert(!has_empty_method<MockList>::value, "");
static_assert(has_empty_method_v<MockVector>, "");
static_assert(!has_empty_method_v<MockList>, "");
static_assert(std::is_same<has_empty_method_t<MockVector>, std::true_type>::value, "");
static_assert(std::is_same<has_empty_method_t<MockList>, std::false_type>::value, "");


// Now, fill in the blanks in these three equivalent implementations.
// version_a should use C++17 `if constexpr`.
// version_b should use tag dispatch on has_empty_method_t<C>.
// version_c should use an overload set with SFINAE.

// If your compiler can't handle C++17, feel free to delete `version_a` and its tests.
// If you feel lost, ask a question!


template<class Container>
bool version_a(const Container& c)
{
    // `if constexpr` version (C++17 only)
    // YOUR CODE GOES HERE
}


template<class Container>
bool version_b_impl(~~~ YOUR CODE GOES HERE
{
    return c.empty();
}

template<class Container>
bool version_b_impl(~~~ YOUR CODE GOES HERE
{
    return c.size() == 0;
}

template<class Container>
bool version_b(const Container& c)
{
    // tag dispatch version
    // YOUR CODE GOES HERE
}


// For version_c, use std::enable_if_t with an appropriate
// condition. Remember, you're trying to trigger substitution failure.
// You could do it in the function's return type, or in the type
// of one of its template parameters, or even function parameters.
// The sample solution will show it in a template parameter.

template<class Container> ~~~ YOUR MODIFICATIONS GO IN THIS AREA
bool version_c(const Container& c)
{
    return c.empty();
}

template<class Container> ~~~ YOUR MODIFICATIONS GO IN THIS AREA
bool version_c(const Container& c)
{
    return c.size() == 0;
}


int main()
{
    // When you're finished, your code should pass all of these unit tests.

    MockVector v;
    MockList w;
    std::vector<int> x;
    assert( version_a(v) );  // v is empty
    assert( version_a(w) );  // w is empty
    assert( version_a(x) );  // x is empty
    assert( version_b(v) );  // v is empty
    assert( version_b(w) );  // w is empty
    assert( version_b(x) );  // x is empty
    assert( version_c(v) );  // v is empty
    assert( version_c(w) );  // w is empty
    assert( version_c(x) );  // x is empty

    v.size_ = 42;
    w.size_ = 42;
    x.resize(42);
    assert( !version_a(v) );  // v is not empty
    assert( !version_a(w) );  // w is not empty
    assert( !version_a(x) );  // x is not empty
    assert( !version_b(v) );  // v is not empty
    assert( !version_b(w) );  // w is not empty
    assert( !version_b(x) );  // x is not empty
    assert( !version_c(v) );  // v is not empty
    assert( !version_c(w) );  // w is not empty
    assert( !version_c(x) );  // x is not empty

    puts("All tests passed!");
}
