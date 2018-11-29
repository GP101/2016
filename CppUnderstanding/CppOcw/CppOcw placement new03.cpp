#include <stdio.h>
#include <stdlib.h>
#include <memory>

char buffer[1024];

class KTest
{
    unsigned int        m_iData;
public:
    KTest()
    {
        m_iData = 0x12345678;
        printf( "KTest()\r\n" );
    }
    ~KTest()
    {
        printf( "~KTest()\r\n" );
    }
    void* operator new( unsigned int size, char* ) // custom operator new
    {
        printf( "operator new size = %i\r\n", size );
        return malloc(size);
    }

    void operator delete( void* p, unsigned int size )
    {
        printf( "custom operator delete p = %p, size = %i\r\n", p, size );
        free( p );
    }

private:
    int i = 3;
};

void main()
{
    KTest* p = nullptr;
    //p = new KTest();
    //delete p;

    p = new (buffer) KTest(); // error
    p->KTest::~KTest();
}
 