#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    uint16_t  value   = 10;
    uint16_t* pointer = &value;
    std::cout << "pointer: " << std::hex << (uint32_t*)pointer << endl;
    pointer++;
    std::cout << "pointer: " << std::hex << (uint32_t*)pointer << endl;

    return 0;
}