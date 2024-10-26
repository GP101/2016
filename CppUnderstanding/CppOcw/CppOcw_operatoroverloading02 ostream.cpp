#include <stdio.h>

class ostream;
void endl(ostream& stream)
{
    printf("\r\n");
}

class ostream
{
public:
    ostream& operator<<(int i)
    {
        printf("%i", i);
        return *this;
    }

    ostream& operator<<(float f)
    {
        printf("%g", f);
        return *this;
    }

    ostream& operator<<(const char* s)
    {
        printf("%s", s);
        return *this;
    }

    ostream& operator<<(void(*manipulator)(ostream&))
    {
        manipulator(*this);
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
