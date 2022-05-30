#include <future>
#include <iostream>
#include <optional>
#include <string>

using namespace std;

int printa(int a)
{
    cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
    return a;
}

int printb(int b)
{
    cout << "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" << endl;
    return b;
}

int printc(int c)
{
    cout << "cccccccccccccccccccccccccccccccccccccccc" << endl;
    return c;
}

const auto fun = []() {
    cout << "fun call..." << endl;
    return 3;
};

int main()
{
    cout << "begin" << endl;

    auto a = std::async(std::launch::async, printa, 10);
    auto b = std::async(std::launch::async, printb, 100);
    auto c = std::async(std::launch::async, printc, 1000);
    cout << "end" << endl;

    cout << a.get() << endl;
    cout << b.get() << endl;
    cout << c.get() << endl;

    std::optional<std::string> op;
    if (op.has_value())
    {
        cout << "has value" << endl;
    }
    op = "aaabbb";
    if (op.has_value())
    {
        cout << "has value1" << endl;
    }
    op.reset();
    if (op.has_value())
    {
        cout << "has value2" << endl;
    }
    cout << "end test" << endl;

    return 0;
}