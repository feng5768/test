#include <iostream>

using namespace std;

class p
{
public:
    p()
    {
        cout << "p ctor" << endl;
    }
    virtual void print()
    {
        cout << "father" << endl;
    }
    ~p()
    {
        cout << "p dtor" << endl;
    }
};
class cld : public p
{
public:
    cld()
    {
        cout << "cld ctor" << endl;
    }
    // virtual void print() override
    // {
    //     cout << "Child" << endl;
    // }
    virtual ~cld()
    {
        cout << "cld dtor" << endl;
    }
};
int main()
{
    // cld* c   = new cld{};
    p* mpp = new cld{};
    mpp->print();

    delete mpp;

    return 0;
}