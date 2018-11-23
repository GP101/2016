#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
//#include <boost/foreach.hpp>
//#include <boost/typeof/typeof.hpp>

bool set_true( bool& bInOutVariable_ )
{
    bInOutVariable_ = true;
    return false;
}

#define FOREACH( statement_, container_ ) \
    if( bool bForBreaker = false ) {} \
    else \
    for( decltype(container_)::iterator  vitor = container_.begin() \
        ; bForBreaker == false && vitor != container_.end() \
        ; ++vitor ) \
        if( set_true(bForBreaker) ) {} \
        else \
            for( statement_ = *vitor; bForBreaker == true; bForBreaker = false )

void main()
{
    std::vector<int>    vecIntData;
    vecIntData.push_back( 1 );
    vecIntData.push_back( 3 );

    FOREACH( int& iData, vecIntData )
    {
        std::cout << iData << std::endl;
        //break;
    }//FOREACH()
}//main()
