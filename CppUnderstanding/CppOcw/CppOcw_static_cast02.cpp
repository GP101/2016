#include <stdio.h>

class KBase
{
public:
    virtual ~KBase() {}
};

class KDerived : public KBase
{
public:
    void Print()
    {
        printf( "KDerived::Print()\r\n" );
    }
};

class KDerived2 : public KBase
{
public:
    void Print()
    {
        printf( "KDerived::Print2()\r\n" );
    }
};

void main( void )
{
    KBase* a = new KBase;
    KDerived* b = static_cast<KDerived*>( a );
    KDerived* c = dynamic_cast<KDerived*>( a );

    if( b != nullptr )
    {
        b->Print();
    }

    if( c != nullptr )
    {
        c->Print();
    }

    KDerived* f = new KDerived();
    KDerived2* g = dynamic_cast<KDerived2*>( f );
    if( g != nullptr )
    {
        g->Print();
    }//if
}//main()
