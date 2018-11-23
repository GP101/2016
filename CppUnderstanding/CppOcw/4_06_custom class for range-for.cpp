#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

class KTest
{
public:
    int     m_idata;

public:
    int* begin()
    {
        return nullptr;
    }
    int* end()
    {
        return nullptr;
    }
};

void main()
{
    for( int iData : KTest{3} ) {
        std::cout << iData << std::endl;
        //break;
    }//FOREACH()

    int a[] {1, 3, 5, 7, 9};
    for( int i : a ) {
        printf( "%i\r\n", i );
    }
}//main()
