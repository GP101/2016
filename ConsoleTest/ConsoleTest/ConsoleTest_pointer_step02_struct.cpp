#include <stdio.h>
#include <stdlib.h>

struct KTest {
    int iAge;
    int iHp;
    int aData[ 4 ];
    int iMp;
};

void main() {
    KTest t = { 1, 3, { 6, 7, 8, 9 }, 5 };
    int* pi;
    pi = (int*)&t;

    printf( "%i,%i,%i\r\n", *( pi + 3 ), pi[ 3 ], 3[ pi ] );
    printf( "%p,%p,%p\r\n", &t, &pi, &t.iHp );
    /*
    7,7,7
    003CFB24,003CFB20,003CFB28
    */
}