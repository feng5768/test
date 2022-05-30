#include "clone_ptr.hpp"
#include <iostream>
#include <string>

struct Sheep {
    int generation = 1;

    Sheep() = default;
    explicit Sheep(int g) { generation = g; }

    Sheep *clone() const {
        return new Sheep(generation + 1);
    }
};

struct Vector {
    bool received_rvalue = false;
    explicit Vector(int, const std::string&) : received_rvalue(false) {}
    explicit Vector(int, std::string&&) : received_rvalue(true) {}

    Vector *clone() const { return nullptr; }
};

struct IntSet {
    explicit IntSet(std::initializer_list<int>) {}

    IntSet *clone() const { return nullptr; }
};


int main() {
    auto p1 = make_clone<Sheep>(42);

    auto p2 = make_clone<Sheep>();
    assert(p2->generation == 1);

    std::string s = "hello world";
    auto p3 = make_clone<Vector>(10, s);
    auto p4 = make_clone<Vector>(10, std::move(s));
    assert(p3->received_rvalue == false);
    assert(p4->received_rvalue == true);

#if 1
    // Uncomment these tests to see one way perfect forwarding isn't quite "perfect".
    // Consider adding a second overload of `make_clone` to handle these calls.

    auto p5 = make_clone<IntSet>({1});
    auto p6 = make_clone<IntSet>({1,2});
    auto p7 = make_clone<IntSet>({1,2,3,4,5,6});
#endif

    std::cout << "All tests passed!\n";
}
