#include <stdio.h>
#include <memory.h>

class KBase
{
public:
    virtual ~KBase()
    {
        printf( "~KBase()\r\n" );
        //DoTest2();
    }
    void Test1()
    {
        printf( "KBase::Test1()\r\n" );
    }
    virtual void Test2() = 0;
    //{
    //    printf( "KBase::Test2()\r\n" );
    //}
    void DoTest2()
    {
        Test2();
    }
};

class KDerived : public KBase
{
public:
    ~KDerived()
    {
        printf( "~KDerived()\r\n" );
    }
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
    //KBase* pa = new KBase();
    KBase* pb = new KDerived();
    pb->DoTest2();
    //pa->Test2();
    //pb->Test2();
    //delete pa;
    delete pb;
}//main()
