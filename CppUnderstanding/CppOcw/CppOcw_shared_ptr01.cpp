#include <stdio.h>
#include <memory>

class KTest
{
private:
    std::shared_ptr<int> ipRef;
public:
    KTest()
    {
        //ipRef = nullptr;
    }
    void SetRefData( std::shared_ptr<int> ip )
    {
        ipRef = ip;
    }
    int GetData() const
    {
        return *ipRef;
    }
    bool IsSafeData() const
    {
        if( ipRef )
            return true;
        return false;
    }
    void Release()
    {
        ipRef.reset();
    }
};

void main()
{
    std::shared_ptr<int> ip;
    ip.reset( new int );
    *ip = 3;

    KTest   t;
    t.SetRefData( ip );
    printf( "%i\r\n", t.GetData() );
    //delete ip;
    ip.reset();
    //ip = nullptr;

    if( t.IsSafeData() )
        printf( "%i\r\n", t.GetData() ); // dangling
    t.Release();
    if( t.IsSafeData() )
        printf( "%i\r\n", t.GetData() ); // dangling
}//int main()
