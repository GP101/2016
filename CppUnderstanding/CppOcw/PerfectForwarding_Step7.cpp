// PerfectForwarding.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <utility>

template<class _Ty>
struct remove_reference
{
    typedef _Ty type;
};

template<class _Ty>
struct remove_reference<_Ty&>
{
    typedef _Ty type;
};

template<class _Ty>
struct remove_reference<_Ty&&>
{
    typedef _Ty type;
};

template<typename T>
typename remove_reference<T>::type&& mymove(T&& t)
{
    return (typename remove_reference<T>::type&&)t;
}

class KTest;
void Test(KTest& t);
void Test(KTest&& t);
void Test2(KTest& t);
void Test2(KTest&& t);

class KTest
{
private:
    int*    pData;
    int     dataSize;
public:
    KTest()
    {
        dataSize = 3;
        pData = new int[ dataSize ];
        printf( "constructor\r\n" );
    }

    KTest( const KTest& rhs ) // copy constructor
    {
        dataSize = rhs.dataSize;
        pData = new int[ dataSize ];
        memcpy( pData, rhs.pData, sizeof( int )*dataSize );
        printf( "copy constructor\r\n" );
    }

    KTest( KTest&& rhs ) // move constructor
    {
        dataSize = rhs.dataSize;
        pData = rhs.pData;

        rhs.dataSize = 0;
        rhs.pData = nullptr;
        printf( "move constructor\r\n" );
    }

    KTest& operator=( const KTest& rhs )
    {
        if( this == &rhs )
            return *this;

        Release();

        dataSize = rhs.dataSize;
        pData = new int[ dataSize ];
        memcpy( pData, rhs.pData, sizeof( int )*dataSize );
        printf( "operator=()\r\n" );
        return *this;
    }

    KTest& operator=( KTest&& rhs ) // move assignment operator
    {
        if( this == &rhs )
            return *this;

        Release();

        dataSize = rhs.dataSize;
        pData = rhs.pData;

        rhs.dataSize = 0;
        rhs.pData = nullptr;

        printf( "move operator=()\r\n" );
        return *this;
    }

    void Release()
    {
        dataSize = 0;
        if( pData != nullptr )
            delete[] pData;
        pData = nullptr;
    }
    ~KTest()
    {
        Release();
        printf( "destructor\r\n" );
    }
};

void Test(KTest& t)
{
    printf("l-value Test()\r\n");
}
void Test(KTest&& t)
{
    printf("r-value Test()\r\n");
}
void Test2(KTest& t)
{
    printf("l-value Test2()\r\n");
    Test( t );
}
void Test2(KTest&& t)
{
    printf("r-value Test2()\r\n");
    Test( t );
}

KTest GetTest()
{
    KTest t;
    return t;
}

void main()
{
    KTest t;
    Test2(t);
    Test2(GetTest());
}