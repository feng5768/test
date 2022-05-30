#include <cassert>
#include <cstdio>
#include <type_traits>
#include <vector>


// has_empty_method<C> is an STL-style type trait template.
// Add a definition for `concept emptyable`, expressed using a
// `requires`-expression.

template<class C>
concept emptyable = YOUR CODE GOES HERE;


// Can you refactor `has_empty_method`, `has_empty_method_t`,
// and `has_empty_method_v` in terms of `emptyable<C>`?

template<class C, class = void>
struct has_empty_method : std::false_type {};

template<class U>  // partial specialization
struct has_empty_method<U, decltype(std::declval<const U&>().empty(), void())> : std::true_type {};

template<class C>
using has_empty_method_t = typename has_empty_method<C>::type;

template<class C>
inline constexpr bool has_empty_method_v = has_empty_method<C>::value;


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


// This is a sample solution to version_a from Lab 5.
// Refactor the `if constexpr` condition to use your
// `concept emptyable` instead of the type-trait.

template<class Container>
auto version_a(const Container& c)
{
    if constexpr (has_empty_method_v<Container>) {
        return c.empty();
    } else {
        return c.size() == 0;
    }
}


// This is a sample solution to version_c from Lab 5.
// Refactor it to use C++20 Concepts syntax instead of C++17 syntax.
// You should keep it as an overload set containing
// two function templates; but now one of them will be
// a constrained template and the other will be unconstrained.

template<class Container>
auto version_c(const Container& c)
    -> decltype(c.empty())
{
    return c.empty();
}

template<class Container>
auto version_c(const Container& c)
    -> std::enable_if_t<!has_empty_method_v<Container>, bool>
{
    return c.size() == 0;
}


int main()
{
    // When you're finished, your code should pass all of these unit tests.

    MockVector v;
    MockList w;
    std::vector<int> x;
    assert( version_c(v) );  // v is empty
    assert( version_c(w) );  // w is empty
    assert( version_c(x) );  // x is empty

    v.size_ = 42;
    w.size_ = 42;
    x.resize(42);
    assert( !version_c(v) );  // v is not empty
    assert( !version_c(w) );  // w is not empty
    assert( !version_c(x) );  // x is not empty

    puts("All tests passed!");
}
