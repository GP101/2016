#include <stdio.h>
#include <vector>
#include "KGlobalSingletonNotGood.h"

class KTest : public KGlobalSingleton<KTest>
{
public:
    KTest()
    {
        printf( "%s\r\n", __FUNCTION__ );
    }
    void Print() const
    {
        printf( "%s\r\n", __FUNCTION__ );
    }
};

#define _KTest  KTest::Singleton()

void main()
{
    printf( "hello\r\n" );
    _KTest.Print();
}
