#include <iostream>
#include <thread>

using namespace std;

void work()
{
    std::cout << "my thread" << std::endl;
}

class backgroundTask
{
public:
    int& i;
    backgroundTask(int& j) : i{j}
    {
    }
    void operator()() const
    {
        while (1)
        {
            std::cout << "backgroundTask" << i << std::endl;
        }
    }
};

class MM
{
public:
    void print()
    {
        std::cout << "MM" << std::endl;
    }
};

int main()
{
    MM          mm;
    std::thread t{&MM::print, &mm};
    t.join();

    return 0;
}