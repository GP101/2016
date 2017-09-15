#include <stdio.h>
#include <string.h>

class KPeople
{
public:
    int age; // data member
    char name[ 12 ];

    KPeople() // constructor
    {
        age = 0;
        name[ 0 ] = 0;
        printf( "constructor()\r\n" );
    }

    ~KPeople() // destructor
    {
        //age = 0;
        printf( "destructor()\r\n" );
    }

    void PrintPeople() // member function
    {
        printf( "%s : %i\r\n", name, age );
    }
    void SetAge( int age_ )
    {
        age = age_;
    }
    void SetName( const char* name_ )
    {
        strcpy( name, name_ );
    }
};

void main()
{
    KPeople* p;
    p = ( KPeople* )operator new( sizeof( KPeople ) );
    p->KPeople::KPeople();
    //p = new KPeople; // new expression

    //p->SetAge( 48 );
    //p->SetName( "John" );
    p->PrintPeople();

    p->KPeople::~KPeople();
    operator delete( p );
    delete p; // delete expression
}
 