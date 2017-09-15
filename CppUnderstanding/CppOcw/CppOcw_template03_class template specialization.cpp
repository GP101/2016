#include <stdio.h>
#include <string.h>

template<typename T, int SIZE = 100>
class KStack
{
public:
    KStack() : sp( 0 ) {}
    void Push( T d )
    {
        data[ sp ] = d;
        ++sp;
    }
    bool Pop( T& d );
    bool IsEmpty() const
    {
        return sp == 0;
    }
private:
    int     sp;
    T       data[ SIZE ];
};//KStack

template<typename T, int SIZE>
bool KStack<T,SIZE>::Pop( T& d )
{
    if( sp == 0 )
        return false;

    --sp;
    d = data[ sp ]; // set [out] parameter
    return true;
}

template<int SIZE>
class KStack<char*,SIZE>
{
public:
    KStack() : sp( 0 ) {}
    void Push( char* d )
    {
        strcpy( data[ sp ], d );
        ++sp;
    }
    bool Pop( char*& d );
    const char* Top() const
    {
        return data[ sp - 1 ];
    }
    bool IsEmpty() const
    {
        return sp == 0;
    }
private:
    int     sp;
    char    data[ SIZE ][20];
};//KStack

template<int SIZE>
bool KStack<char*, SIZE>::Pop( char*& d )
{
    if( sp == 0 )
        return false;

    --sp;
    d = data[ sp ]; // set [out] parameter
    return true;
}

void main()
{
    KStack<int,10>      s;
    KStack<float>   s2;

    s.Push( 3 );
    s.Push( 5 );
    int i = 0;
    s.Pop( i );
    printf( "%i\r\n", i );

    KStack<char*>   s3;
    s3.Push( "hello" );
    s3.Push( "world" );
    printf( "%s\r\n", s3.Top() );
}//main()
