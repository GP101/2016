#include <stdio.h>

/**
Url: http://www.drdobbs.com/a-portable-typeof-operator/184401310
*/

// No definition, only specializations
template<int N> struct select_type;

template<> struct select_type <1> { typedef short type; };
template<> struct select_type <2> { typedef int type; };
template<> struct select_type <3> { typedef long type; };

typedef char CharArrayOf1[1];
typedef char CharArrayOf2[2];
typedef char CharArrayOf3[3];

CharArrayOf1* select_array( short );
CharArrayOf2* select_array( int );
CharArrayOf3* select_array( long );

#define typeof(x) \
    select_type <sizeof(*select_array(x))>::type

void main()
{
    typeof( 3 + 4 )     i;
    i = 9;
    printf( "%i\r\n", i );
}