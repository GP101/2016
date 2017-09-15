#include <memory>

template<typename T, typename... Args>
std::unique_ptr<T> mymake_unique( Args&&... args )
{
    return std::unique_ptr<T>( new T( std::forward<Args>( args )... ) );
}

class KTest
{
public:
    KTest( int, const char*, float )
    {
        printf( "constructor\r\n" );
    }
};
void main()
{
    std::unique_ptr<KTest> f = mymake_unique<KTest>( 1, "str", 2.13f );
}