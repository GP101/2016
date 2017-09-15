#include <stdio.h>

void endl()
{
    printf( "\r\n" );
}

class ostream
{
public:
    const ostream& operator<<( int i ) const
    {
        printf( "%i", i );
        return *this;
    }

    const ostream& operator<<( float f ) const
    {
        printf( "%g", f );
        return *this;
    }

    const ostream& operator<<( const char* s ) const
    {
        printf( "%s", s );
        return *this;
    }

    const ostream& operator<<( void( *manipulator )( ) ) const
    {
        manipulator();
        return *this;
    }

};

ostream cout;

//const ostream& operator<<( const char* left, void( *manipulator )( ) )
//{
//    printf( "%s", left );
//    manipulator();
//    return cout;
//}

void main()
{
    int i = 3;
    float f = 4.1f;
    //cout.operator<<( i ).operator<<( f ).operator<<( "hello" ); // explicit call
    cout << i << " " << f << " " << "hello" << endl;
}
 