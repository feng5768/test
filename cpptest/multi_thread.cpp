#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

using namespace std;

std::mutex m_mutexA;
std::mutex m_mutexB;

std::vector<string> m_string;

void pushA()
{
    std::lock_guard guard1(m_mutexA);
    std::lock_guard guard2(m_mutexB);
    m_string.push_back("a");
}

void pushB()
{
    std::lock_guard guard1(m_mutexB);
    std::lock_guard guard2(m_mutexA);
    m_string.push_back("b");
}
int main(int argc, char** argv)
{
    cout << "hello multi" << endl;
    vector<thread> threads{2};

    threads[0] = thread([]() {
        for (int i = 0; i < 5; ++i)
        {
            pushA();
        }
    });

    threads[1] = thread([]() {
        for (int i = 0; i < 5; ++i)
        {
            pushB();
        }
    });

    threads[0].join();

    threads[1].join();

    for (auto str : m_string)
    {
        cout << str << endl;
    }

    return 0;
}