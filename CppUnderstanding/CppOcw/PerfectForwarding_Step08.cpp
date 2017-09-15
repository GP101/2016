// PerfectForwarding.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <utility>

class KTest;
class KContainer;
void Test(KTest& t);
void Test(KTest&& t);
void Test(KContainer& t);
void Test(KContainer&& t);

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

class KContainer
{
private:
    KTest t;
public:
    KContainer() {}
    KContainer( const KContainer& rhs ) {}
    KContainer( KContainer&& rhs )
    {
        //KTest t = std::move(rhs.t); // call copy constructor
        //Test((KTest&&)rhs.t);
        //Test(std::move(rhs.t));
        //Test(std::forward(rhs.t));

        Test(std::move(rhs));
        //Test(std::forward(rhs));
    }
    ~KContainer() {}
};

void Test(KTest& t)
{
    printf("l-value Test()\r\n");
}
void Test(KTest&& t)
{
    printf("r-value Test()\r\n");
}

void Test(KContainer& t)
{
    printf("l-value KContainer Test()\r\n");
}
void Test(KContainer&& t)
{
    printf("r-value KContainer Test()\r\n");
}

KTest GetTest()
{
    KTest t;
    return t;
}

KContainer GetContainer()
{
    KContainer c;
    return c;
}

void main()
{
    //KTest t = GetTest();
    KContainer c = GetContainer();
}