#include <algorithm>
#include <cassert>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>

class Book {
    std::string title_;
    std::string author_;
public:
    explicit Book(std::string title, std::string author)
        : title_(std::move(title)), author_(std::move(author)) {}

    const std::string& title() const { return title_; }
    const std::string& author() const { return author_; }


    // operators < <= > >= can all be replaced by the rewritten candidates
    // generated from a single operator<=>.
    // But it cannot be defaulted, because the default behavior would
    // sort by title first, and we want to sort by author first.

    friend auto operator<=>(const Book& a, const Book& b) {
        return std::tie(a.author_, a.title_) <=> std::tie(b.author_, b.title_);
    }

    // Since we wrote a non-defaulted operator<=>, the compiler
    // does not provide a defaulted operator== automatically.
    // We must explicitly opt into it. But this one can be defaulted.

    friend bool operator==(const Book& a, const Book& b) = default;

    // operator!= is no longer needed, because the expression (a != b)
    // can use the rewritten candidate: call (a == b) and negate the result.


    // -- YOUR CODE GOES ABOVE HERE


    struct ByAuthor {
        bool operator()(const Book& a, const Book& b) const {
            return a.author() < b.author();
        }
    };

    struct ByTitle {
        bool operator()(const Book& a, const Book& b) const {
            return a.title() < b.title();
        }
    };
};

int main()
{
    std::vector<Book> shelf = {
        Book("The Lost World", "Crichton"),
        Book("The Adventures of Sherlock Holmes", "Doyle"),
        Book("The Lost World", "Doyle"),
    };

    assert(std::is_sorted(shelf.begin(), shelf.end()));
    assert(std::is_sorted(shelf.begin(), shelf.end(), Book::ByAuthor()));
    assert(!std::is_sorted(shelf.begin(), shelf.end(), Book::ByTitle()));

    assert(shelf[0] == shelf[0]);
    assert(shelf[0] != shelf[1]);

#if 0
    // In C++20 we can write the assertions this way.

    assert(std::ranges::is_sorted(shelf));
    assert(std::ranges::is_sorted(shelf, {}, &Book::author));
    assert(!std::ranges::is_sorted(shelf, {}, &Book::title));
#endif

    puts("All tests passed!");
}
