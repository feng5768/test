#include <iostream>

template<class... Ts>
auto right_fold(Ts... ts) {
    return (ts - ...);
}

template<class... Ts>
auto left_fold(Ts... ts) {
    return (... - ts);
}

template<class... Ts>
void print(Ts&&... ts) {
    (std::cout << ... << static_cast<Ts&&>(ts)) << "\n";
}

int main() {
    print("Right-folding 1 - (2 - 3): ", right_fold(1, 2, 3));
    print("left-folding (1 - 2) - 3: ", left_fold(1, 2, 3));
    print(
        "Right-folding \"hello world\" - (2 - ('i' - 'a')): ",
        right_fold("hello world", 2, 'i', 'a')
    );
}
