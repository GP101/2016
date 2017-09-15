#include <stdio.h>
#include <algorithm>
#include <memory>

class KTest;
void Test( std::shared_ptr<KTest> sp );

class KTest : public std::enable_shared_from_this<KTest>
{
public:
    // factory
    static std::shared_ptr<KTest> CreateObject()
    {
        std::shared_ptr<KTest> sp;
        sp.reset( new KTest() );
        return sp;
    }

    KTest() {}
    void Print()
    {
        Test( __super::shared_from_this() );
    }
};

void Test( std::shared_ptr<KTest> sp )
{
}

void main()
{
    std::shared_ptr<KTest> sp0;
    sp0 = KTest::CreateObject();

    if( sp0 != nullptr )
        sp0->Print();
}//int main()
