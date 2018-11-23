#include <stdio.h>
#include <set>
#include <algorithm>

class KPoint
{
public:
    int x;
    int y;
public:
    KPoint( int x_, int y_ ) : x(x_), y(y_)
    {
    }
    bool operator<( const KPoint& rhs ) const
    {
        //return y < rhs.y && x < rhs.x;
        if( y != rhs.y )
            return y < rhs.y;
        return x < rhs.x;
    }
    bool operator==( const KPoint& rhs ) const
    {
        return x == rhs.x && y == rhs.y;
    }
};

void main()
{
    std::set<KPoint>   s1;
    s1.insert( KPoint(1,1) );
    s1.insert( KPoint(2,5) );
    s1.insert( KPoint(1,2) );
    s1.insert( KPoint(1,5) );
    for( const KPoint& v : s1 ) {
        printf( "(%i,%i)\r\n", v.x, v.y );
    }
    std::find( s1.begin(), s1.end(), KPoint( 1, 2 ) );
}//main()
