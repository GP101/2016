#include <stdio.h>
#include <string.h>

class KPeople
{
public:
    int age;
    char name[ 12 ];

    KPeople() // default constructor
    {
        age = 0;
        name[ 0 ] = 0;
        printf( "constructor()\r\n" );
    }
    explicit KPeople( const char* name_) // overloading
    {
        age = 0;
        strcpy( name, name_ );
        printf( "constructor( char* )\r\n" );
    }
    KPeople( const KPeople& rhs ) // copy constructor
    {
        age = rhs.age;
        strcpy( name, rhs.name );
        printf( "copy constructor()\r\n" );
    }
    ~KPeople()
    {
        printf( "destructor()\r\n" );
    }
    void PrintPeople()
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

void Test( KPeople p )
{
    p.PrintPeople();
}

void main()
{
    KPeople p( "John" ); // implicit construction call
    KPeople temp = p;//KPeople( "Mike" );
    Test( temp ); // temporary object
}
 