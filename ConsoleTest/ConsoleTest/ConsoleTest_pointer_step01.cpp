#include <stdio.h>
#include <stdlib.h>

void f( int x, int y ) {
    int i;
    int j;
    printf( "%p,%p,%p,%p\r\n", &x, &y, &i, &j );
}

void main() {
    int i;
    int j;
    i = 2;
    j = i;
    printf( "%p,%p,%p,%p\r\n", &f, f, &i, &j );
    f( i, j );

    int a[ 3 ] = { 1, 3, 5 };
    printf( "%i,%i,%i\r\n", *( a + 1 ), a[ 1 ], 1[ a ] );
    printf( "%p,%p,%p\r\n", a, &a, &a[ 0 ] );

    int b[ 3 ][ 2 ] = { { 1, 3 }, { 5, 7 }, { 9, 11 } };
    printf( "%p,%p\r\n", b[ 1 ], b[ 2 ] );
    printf( "%p,%p\r\n", b, b[ 0 ] );
    printf( "%i,%i,%i\r\n", b[ 1 ], *b[ 1 ], **b );
    /*
    00211000,00211000,0036F79C,0036F798
    0036F794,0036F790,0036F78C,0036F788
    3,3,3
    0036F7B8,0036F7B8,0036F7B8
    0036F7A8,0036F7B0
    0036F7A0,0036F7A0
    3602344,5,1
    */
}