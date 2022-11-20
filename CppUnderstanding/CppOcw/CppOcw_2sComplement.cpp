#include <stdio.h>

void main()
{
    char c = 128;
    int c2 = 0b10000000;
    printf("%i\n", c); // -128 is 2's complement of 1000 0000
    printf("%i\n", c2); // 128
}
