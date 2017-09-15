#include <stdio.h>
#include <algorithm>
#include <memory>

class KChild;
class KParent
{
public:
    std::shared_ptr<KChild>  spChild;
    ~KParent()
    {
        printf( "KParent destructor\r\n" );
    }
};

class KChild
{
public:
    std::weak_ptr<KParent>  spParent;
    ~KChild()
    {
        printf( "KChild destructor\r\n" );
    }
};

void main()
{
    std::shared_ptr<KParent>    spParent;
    std::shared_ptr<KChild>     spChild;

    spParent.reset( new KParent() );
    spChild.reset( new KChild() );

    spParent->spChild = spChild;
    spChild->spParent = spParent;

    if( spParent != nullptr )
        printf( "%i\r\n", spParent.use_count() );
    if( spChild != nullptr )
        printf( "%i\r\n", spChild.use_count() );

    {
        std::shared_ptr<KParent>    spTemp = spChild->spParent.lock();
        if( spTemp != nullptr )
        {
        }//
    }

    spChild.reset();
    spParent.reset();
}//int main()
