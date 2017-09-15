#include <stdio.h>
#include <memory.h>

class KBase;

typedef void ( KBase::*FP )();

class KBase
{
    int i, j, k;
public:
    KBase()
    {
        i = 1;
        j = 5;
        k = 3;
    }
    void A()
    {
        int*    p = reinterpret_cast<int*>( this );

        printf( "%d\n", p[ 1 ] );
        printf( "%d\n", p[ 2 ] );

        void*** po = ( void*** )this;
        void**  pvtbl = (void**)( *po );
        void*   pfn = (void*)pvtbl[ 0 ];
        FP      fp;
        memcpy( &fp, &pfn, 4 );

        ( this->*fp )( );
    }
    virtual void C()
    {
        printf( "KBase::C()\r\n" );
    }
    virtual void B()
    {
        printf( "KBase::B()\r\n" );
    }
};//class KBase

class KDerived : public KBase
{
public:
    virtual void C()
    {
        printf( "KDerived::C()\r\n" );
    }
    virtual void D()
    {
        printf( "KDerived::D()\r\n" );
    }
    void E()
    {
        printf( "KDerived::E()\r\n" );
    }
};//class KDerived

void main()
{
    KDerived a;
    a.A();
}//main()
