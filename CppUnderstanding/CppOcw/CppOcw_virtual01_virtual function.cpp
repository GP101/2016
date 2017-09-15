#include <stdio.h>
#include <memory.h>

class KBase
{
public:
    void Test1()
    {
        printf( "KBase::Test1()\r\n" );
    }
    virtual void Test2()
    {
        printf( "KBase::Test2()\r\n" );
    }
};

class KDerived : public KBase
{
public:
    virtual void Test2() override
    {
        printf( "KDerived::Test2()\r\n" );
    }
    void Test3()
    {
        printf( "KDerived::Test3()\r\n" );
    }
};

void main()
{
    KBase* pa = new KBase();
    KBase* pb = new KDerived();
    pa->Test2();
    pb->Test2();
    delete pa;
    delete pb;
}//main()
