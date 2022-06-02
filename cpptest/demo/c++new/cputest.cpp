#include <cpuid.h>
#include <iostream>

void getCpuid(unsigned int  function,
                              unsigned int* eax,
                              unsigned int* ebx,
                              unsigned int* ecx,
                              unsigned int* edx)
{
    __get_cpuid(function, eax, ebx, ecx, edx);
}

constexpr uint32_t k_TopologyFunction       = 0x8000001e;


int main()
{
    unsigned int eax = 0;
    unsigned int ebx = 0;
    unsigned int ecx = 0;
    unsigned int edx = 0;

    getCpuid(k_TopologyFunction, &eax, &ebx, &ecx, &edx);
    std::cout<<"eax: "<<eax<<"ebx: "<<ebx<<"ecx: "<<ecx<<"edx: "<<edx<<std::endl;

    return 0;
}