#include <stdio.h>
#include <utility>

int i = 1; // global namespace

namespace dsu
{
    int i = 2;
    int j = 3;

    class KTest
    {
    public:
        void Print()
        {
            j += 1;
            printf( "%i\r\n", ::i );
            printf( "%i\r\n", dsu::i );
        }
        static int GetInt()
        {
            return i;
        }
    public:
        static const int i = 4;
    };

    class KDerived : public KTest
    {
    public:
        using KTest::Print;
        void Print(int i) // overloading
        {
            printf( "KDerived::Print()\r\n" );
        }
    };
}

namespace dsu
{
    int k = 5;
}

using namespace dsu;

void main()
{
    printf( "%i\r\n", j );
    printf( "%i\r\n", ::i );
    ::printf( "%i\r\n", dsu::i );

    dsu::KDerived   d;
    d.Print();
    d.Print(3);

    int a = 2;
    int b = 3;
    std::swap( a, b );
    printf( "%i,%i\r\n", a, b );
}
