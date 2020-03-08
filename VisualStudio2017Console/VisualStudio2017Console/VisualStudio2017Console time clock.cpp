#include <ctime>
#include <windows.h>
#include <iostream>

void main()
{
    clock_t begin = clock();

    Sleep( 100 );

    clock_t end = clock();
    double elapsed_secs = double( end - begin ) / CLOCKS_PER_SEC;
    std::cout << elapsed_secs << std::endl;
}