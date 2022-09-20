#include <stdio.h>

void Allocate10Int(int* ip)
{
    ip = new int[10];
}

void main()
{
    int* ip = nullptr;
    Allocate10Int(ip);
    for (int i = 0; i < 10; ++i)
        ip[i] = i;
    for (int i = 0; i < 10; ++i)
        printf("%i, ", ip[i]);
}
