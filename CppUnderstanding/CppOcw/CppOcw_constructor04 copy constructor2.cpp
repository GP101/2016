#include <stdio.h>
#include <string.h>

class KPeople
{
public:
    int age;
    char* name;

    KPeople() // default constructor
    {
        age = 0;
        name = new char[ 10 ];
        printf( "default constructor()\r\n" );
    }
    KPeople( const char* name_ ) // overloading
    {
        age = 0;
        name = new char[ 10 ];
        strcpy( name, name_ );
        printf( "constructor( char* )\r\n" );
    }
private:
    KPeople( const KPeople& rhs ) // copy constructor
    {
        printf( "copy constructor()\r\n" );
        Release();
        age = rhs.age;
        name = new char[ 10 ];
        strcpy( name, rhs.name );
    }
public:
    void Release()
    {
        if( name != nullptr )
        {
            delete[] name;
            name = nullptr;
        }//if
        printf( "Release()\r\n" );
    }
    ~KPeople()
    {
        printf( "destructor() %s\r\n", name );
        Release();
    }
    void PrintPeople() const
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

void Test( const KPeople p )
{
    p.PrintPeople();
}

void main()
{
    //KPeople p( "John" ); // implicit construction call
    //KPeople temp = KPeople( "Mike" );
    Test( KPeople("Mary") ); // temporary object
}
 