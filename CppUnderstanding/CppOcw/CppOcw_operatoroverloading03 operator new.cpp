#include <stdio.h>

int buffer[1024];

class KTest
{
public:
    KTest()
    {
        printf( "KTest()\r\n" );
    }
    ~KTest()
    {
        printf( "~KTest()\r\n" );
    }
    void* operator new( unsigned int size ) // custom operator new
    {
        printf( "operator new size = %i\r\n", size );
        return buffer;
    }

    void* operator new[]( unsigned int size ) // custom operator new
    {
        printf( "operator new[] size = %i\r\n", size );
        return buffer;
    }

    void* operator new( unsigned int size, const char* msg, int ivalue ) // overloading
    {
        printf( "custom operator new size = %i, msg = %s, ivalue = %i\r\n", size, msg, ivalue );
        return buffer;
    }

    void operator delete( void* p, unsigned int size )
    {
        printf( "custom operator delete p = %p, size = %i\r\n", p, size );
    }

    void operator delete[]( void* p, unsigned int size )
    {
        printf( "custom operator delete[] p = %p, size = %i\r\n", p, size );
    }
private:
    int i = 3;
};

void main()
{
    KTest* p;

    p = (KTest*)::operator new( sizeof(KTest) );
    p->KTest::KTest();
    p->KTest::~KTest();
    ::operator delete( p );

    printf( "\r\nsecond phase\r\n" );

    p = new ("hello", 4) KTest();
    delete p;
    for( int i : buffer )
    {
        if( i == 0 ) break;
        printf( "%i, ", i );
    }//for

    printf( "\r\nthird phase\r\n" );

    p = new KTest[ 5 ];
    delete[] p;

    for( int i : buffer )
    {
        if( i == 0 ) break;
        printf( "%i, ", i );
    }//for
}
 