#include <stdio.h>
#include <conio.h>
#include <windows.h>

void main()
{
    const float f = 1.0f / 3.0f;
    printf( "%g\r\n", f );
    if (f == 0.333333f )
        printf( "hello\r\n" );
}
