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
    explicit operator bool()
    {
        return true;
    }
    //operator int()
    //{
    //    return 2;
    //}
    //operator const int*( ) const
    //{
    //    return &istatic;
    //}
    //void unspecified_bool()
    //{
    //}
    //typedef void (KTest::*unspecified_bool_type)();
    //operator unspecified_bool_type()
    //{
    //    return &KTest::unspecified_bool;
    //}
};

void main()
{
    KTest t;
    KTest u;

    if( t )
        printf( "hello\r\n" );
}//int main()
