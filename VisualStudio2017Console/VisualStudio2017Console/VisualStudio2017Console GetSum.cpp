#include <stdio.h>

void GetSum(int* result, int n, int m)
{
    int i = 1;
    int s = 0;
    while (i <= n)
    {
        if (i % m == 0)
            s += i;
        i += 1;
    }
    *result = s;
}

void main()
{
    int sum = 0;
    GetSum(&sum, 100, 3);
    printf("%i\r\n", sum);
}