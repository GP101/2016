#include <stdio.h>
#include <vector>

int g_ivalue = 3;

class KTest
{
public:
    KTest( int& iref ) : m_iref(iref)
    {
    }
    KTest& operator()( int i )
    {
        printf( "%i", i );
        return *this;
    }
    KTest& operator()( float f )
    {
        printf( "%g", f );
        return *this;
    }
    KTest& operator()( const char* text )
    {
        printf( text );
        return *this;
    }
private:
    int& m_iref;
};

int& AccessInt()
{
    int i = 0;
    return i;
}

void Test( const int& i )
{
}

void main()
{
    KTest   t( g_ivalue );
    int i = 1;
    t( i )( 4.0f )( "hello" );

    AccessInt() = 2;

    Test( 3 );

    std::vector<int>    v;
    v.push_back( 1 );
    v.push_back( 3 );
    for( std::vector<int>::iterator it = v.begin(); it != v.end(); ++it )
    {
        const int& value = *it;
        printf( "%i\r\n", value );
    }
}