#include <algorithm>
#include <vector>

bool f( int value )
{
    return value == 5;
}

template<typename T, typename U>
T find_if2( T first, T last, U predicate_ )
{
    int ret = 0;
    while (first != last) {
        if (predicate_( *first )) {
            return first;
        }
        ++first;
    }
    return last;
}//find_if2()

void main()
{
    std::vector<int>    v{ 1,3,5,7,9 };
    //std::vector<int>::iterator it = std::find_if( v.begin(), v.end(), f );
    std::vector<int>::iterator it = find_if2( v.begin(), v.end(), f );
    if (it != v.end() )
    {
        printf( "found value\r\n" );
    }
}