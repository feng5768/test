#include <iostream>

using namespace std;

namespace A
{
namespace B
{
void b()
{
    cout << "bb" << endl;
}
}  // namespace B

void a()
{
    cout << "aa" << endl;
    B::b();
}

}  // namespace A

int main()
{
    cout << "test begin" << endl;

    using namespace A;
    a();

    return 0;
}