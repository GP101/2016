#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <boost/foreach.hpp>

void main()
{
    std::vector<int>    vecIntData;
    vecIntData.push_back( 1 );
    vecIntData.push_back( 3 );
    for( std::vector<int>::iterator  vitor = vecIntData.begin();
        vitor != vecIntData.end();
        ++vitor )
    {
        int& iData = *vitor;
        std::cout << iData << std::endl;
    }//for
}//main()
