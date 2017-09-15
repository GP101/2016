#include <stdio.h>

/**
    Url: http://www.drdobbs.com/a-portable-typeof-operator/184401310
*/

// No definition, only specializations
template<int N> struct select_type;

template<> struct select_type <1> { typedef short Type; };
template<> struct select_type <2> { typedef int Type; };
template<> struct select_type <3> { typedef long Type; };
typedef char CharArrayOf1[1];
typedef char CharArrayOf2[2];
typedef char CharArrayOf3[3];

typedef CharArrayOf1 *PtrCharArrayOf1;
typedef CharArrayOf2 *PtrCharArrayOf2;
typedef CharArrayOf3 *PtrCharArrayOf3;

PtrCharArrayOf1 select_array(short); // No definitions needed
PtrCharArrayOf2 select_array(int);
PtrCharArrayOf3 select_array(long);

#define TYPEOF(x)                               \
    select_type <sizeof(*select_array(x))>::Type

void main()
{
    TYPEOF(3 + 4) i;
    i = 9;
    printf("%i\r\n", i);
}