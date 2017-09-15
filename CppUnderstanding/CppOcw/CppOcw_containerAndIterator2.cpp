#include <stdio.h>
#include <vector>

void main()
{
    std::vector<int>    v;
    v.push_back( 1 );
    v.push_back( 3 );
    v.push_back( 5 );
    v.push_back( 7 );
    v.push_back( 9 );

    //for( int i = 0; i < v.size(); ++i )
    //{
    //    printf( "%i\r\n", v[ i ] );
    //}

    std::vector<int>::iterator it;
    for( it = v.begin(); it != v.end(); ++it )
    {
        const int i = *it;
        printf( "%i\r\n", i );
    }
}//main()