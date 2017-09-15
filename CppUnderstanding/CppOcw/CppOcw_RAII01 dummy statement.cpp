#include <stdio.h>

#define STRING_CAT(a, b)        _STRING_CAT(a, b)
#define _STRING_CAT(a, b)       a ## b

#define DUMMY                   int _STRING_CAT( _dummy, __LINE__ ) = 0

void main()
{
    DUMMY;
    DUMMY;
}