#include <stdio.h>
#include <conio.h>
#include <windows.h>

void Alloc(int* ip)
{
    ip = new int;
}

void Free(int* ip)
{
    delete ip;
}

void main()
{
    int* ip = NULL;

    Alloc(ip);
    *ip = 3; // crash
    (*ip) += 1;
    printf("%d\r\n", *ip);
    Free(ip);
}
