#include <stdio.h>
#include <vector>

template<typename T>
class myvector
{
public:
    typedef T*  iterator;
private:
    T       data[ 100 ];
    int     ibegin;
    int     iend;
public:
    myvector()
    {
        ibegin = 0;
        iend = 0;
    }
    void push_back( const T& i )
    {
        data[ iend ] = i;
        iend += 1;
    }
    T& operator[]( int index )
    {
        return data[ index ];
    }
    int size() const
    {
        return iend - ibegin;
    }
    iterator begin()
    {
        return &data[ ibegin ];
    }
    iterator end()
    {
        return &data[ iend ];
    }
};

void main()
{
    myvector<int>    v;
    v.push_back( 1 );
    v.push_back( 3 );
    v.push_back( 5 );
    v.push_back( 7 );
    v.push_back( 9 );

    //for( int i = 0; i < v.size(); ++i )
    //{
    //    printf( "%i\r\n", v[ i ] );
    //}

    myvector<int>::iterator it;
    for( it = v.begin(); it != v.end(); ++it )
    {
        const int i = *it;
        printf( "%i\r\n", i );
    }
}//main()