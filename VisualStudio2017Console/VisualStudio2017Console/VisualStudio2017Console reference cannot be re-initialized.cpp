#include <stdio.h>

int main()
{
    int i = 0;
    int j = 1;
    int& iref = i;
    int& jref = j;
    iref = jref; // you can't change the original reference, it just copies the data. 'i' will be 1.
    iref += 2; // 'i' will be increased by 2.
    printf("%d,%d\r\n", i, j); // 3,1
    return 0;
}
