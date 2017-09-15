#include <stdio.h>
#include <stdlib.h>

class KTest
{
public:
    KTest()
    {
        printf( "initialize\r\n" );
    }
    ~KTest()
    {
        printf( "finalize\r\n" );
    }
private:
    int i = 3;
};

KTest& operator+=( KTest& lhs, int rhs )
{
    printf( "operator+()\r\n" );
    return lhs;
}

void main()
{
    KTest t;
    operator +=( t, 4 );

    KTest* p;

    //p = ( KTest* )malloc( sizeof( KTest ) );
    // new expression
    p = ( KTest* )operator new( sizeof( KTest ) ); // new function
    p->KTest::KTest();

    //free( p );
    p->~KTest();
    operator delete( p );
}
