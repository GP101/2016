#include <iostream>
#include <stdio.h>
#include <list>
#include <iterator>
#include <limits>
#include "MallocAlloc.h"

void main()
{
    int a[5] = { 1, 3, 5, 7, 9 };
    typedef std::list<int, MallocAlloc<int> >   LIST;
    LIST    list1( &a[0], &a[5] );
    std::ostream_iterator<int> out( std::cout, "," );
    std::copy( list1.begin(), list1.end(), out );
    std::cout << std::endl;
/*
1,3,5,7,9,
Press any key to continue
*/
}//main()
