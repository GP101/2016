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

private:
    int i = 3;
};

void main()
{
    KTest* p = nullptr;
    p = new KTest();
    delete p;

    //p = ( KTest* )::operator new( sizeof( KTest ) );
    //p->KTest::KTest();
    //p->KTest::~KTest();
    //::operator delete( p );

    p = new (buffer) KTest();
    p->KTest::~KTest();
}
 