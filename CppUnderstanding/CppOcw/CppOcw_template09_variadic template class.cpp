#include <stdio.h>
#include <memory>

class KBase1
{
public:
    KBase1( int i ) {}
};

class KBase2
{
public:
    KBase2( float f ) {}
};

template <typename... BaseClasses> class KTest : public BaseClasses...
{
public:
    KTest( BaseClasses&&... base_classes ) : BaseClasses( base_classes )... {}
};

template<typename T, typename... Args>
std::unique_ptr<T> mymake_unique( Args&&... args )
{
    return std::unique_ptr<T>( new T( std::forward<Args>( args )... ) );
}

class KTest2
{
public:
    KTest2( int i, const char* s, float f )
    {
        printf( "constructor %i, %s, %g\r\n", i, s, f );
    }
};

void main()
{
    int i = 2;
    float f = 3.1f;
    KTest<KBase1, KBase2>    t( i, f );

    std::unique_ptr<KTest2> sp = mymake_unique<KTest2>( 1, "hello", 2.1f );
}