#include <iostream>
#include <vector>

int main()
{
    auto l = []<typename T>(std::vector<T>& v, auto f) {
        std::cout << f << std::endl;
        return v.size();
    };

    std::vector<int> vec{1, 2, 3, 4, 5};
    return l(vec, "hahhaha");
}