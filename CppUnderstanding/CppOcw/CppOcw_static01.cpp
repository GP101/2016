#include <stdio.h>

void Test()
{
    static int g_int = 0;
    g_int += 1;
    printf( "%i\r\n", g_int );
}

class KFoo
{
public:
    KFoo()
    {
        printf( "%s\r\n", __FUNCTION__ );
    }
    static KFoo     ms_foo;
};

KFoo     KFoo::ms_foo;

void main()
{
    printf( "hello\r\n" );
}