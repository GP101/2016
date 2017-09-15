#include <stdio.h>
#include <algorithm>
#include <memory>

template<typename T>
class enable_shared_from_this
{
protected:
    std::weak_ptr<T>    weskSelf;

public:
    std::shared_ptr<T> shared_from_this()
    {
        return weskSelf.lock();
    }
    void SetWeakPtr( std::shared_ptr<T> sp )
    {
        weskSelf = sp;
    }
};

class KTest : public enable_shared_from_this<KTest>
{
public:
    KTest()
    {
    }
};

void main()
{
    KTest t;
    std::shared_ptr<KTest>  sp;
    sp.reset( new KTest() );
    sp->SetWeakPtr( sp );
}//int main()
