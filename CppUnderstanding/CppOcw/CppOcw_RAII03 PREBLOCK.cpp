#include <stdio.h>

#define STRING_CAT(a, ...)          _STRING_CAT(a, __VA_ARGS__)
#define _STRING_CAT(a, ...)         a ## __VA_ARGS__

template <typename F>
struct ScopeExit
{
    ScopeExit( F f ) : f( f ) {}
    ~ScopeExit() { f(); }
    operator bool()
    {
        return true;
    }

    F f;
};
template <typename F>
ScopeExit<F> MakeScopeExit( F f )
{
    return ScopeExit<F>( f );
};

#define SCOPE_EXIT( code )      auto STRING_CAT( scope_exit_, __LINE__ ) = MakeScopeExit( [=]() { code; } )
#define PREBLOCK( code )        if( SCOPE_EXIT( code ) )

int g_value = 1;

int Test( int value )
{
    PREBLOCK( g_value = 1; printf( "exit if\r\n" ); )
    {
        printf( "inside if\r\n" );
    }

    printf( "inside test\r\n" );
    if( value == 0 )
        return 0;
    else if( value == 1 )
    {
        g_value = 2;
        return 2;
    }

    return 99;
}

void main()
{
    printf( "before test call\r\n" );
    Test( 1 );

    printf( "after test call, %i\r\n", g_value );
}