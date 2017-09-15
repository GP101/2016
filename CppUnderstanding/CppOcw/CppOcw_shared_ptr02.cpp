#include <stdio.h>

template<typename T>
struct shared_ptr_traits
{
    typedef T&  reference;
};

template<>
struct shared_ptr_traits<void>
{
    typedef void   reference;
};

shared_ptr_traits<int>::reference Test()
{
    static int i = 0;
    return i;
}

shared_ptr_traits<void>::reference Test2()
{
}

class KTest
{
private:
    static const int istatic = 0;

public:
    operator bool()
    {
        return true;
    }
    operator int()
    {
        return 2;
    }
    operator const int*( ) const
    {
        return &istatic;
    }
};

void main()
{
    KTest t;
    if( t )
        printf( "hello\r\n" );
}//int main()
