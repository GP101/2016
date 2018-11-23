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

void main()
{
    std::vector<int>    vecIntData;
    vecIntData.push_back( 1 );
    vecIntData.push_back( 3 );

    //BOOST_FOREACH( int& iData, vecIntData )
    if( bool bForBreaker = false ) {}
    else
    //for( BOOST_TYPEOF(vecIntData)::iterator  vitor = vecIntData.begin()
    for( decltype(vecIntData)::iterator  vitor = vecIntData.begin()
        ; bForBreaker == false && vitor != vecIntData.end()
        ; ++vitor )
    {
        if( set_true(bForBreaker) ) {}
        else
        for( int& iData = *vitor; bForBreaker == true; bForBreaker = false )
        {
            std::cout << iData << std::endl;
            //break;
        }//for
    }//for
}//main()
