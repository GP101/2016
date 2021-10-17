// PerfectForwarding.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <utility>

class KTest
{
public:
    KTest() {}
    ~KTest() {}
};

//void Test(KTest t)
//{
//    printf("value\n");
//}

void Test(KTest& t)
{
    printf("l-value\n");
}

void Test(KTest&& t)
{
    printf("r-value\n");
}

void main()
{
    KTest t;
    Test(t);
    Test(KTest());
}
