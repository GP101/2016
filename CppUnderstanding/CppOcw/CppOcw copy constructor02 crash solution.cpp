#include <stdio.h>
#include <vector>

class KTest
{
private:
    static const int bufferSize = 100;
    char*   _buffer = nullptr;
public:
    KTest()
    {
        _buffer = new char[bufferSize];
    }
    KTest( const KTest& rhs )
    {
        _buffer = new char[bufferSize];
        memcpy( _buffer, rhs._buffer, sizeof(char)* bufferSize );
    }
    KTest& operator=( const KTest& rhs )
    {
        Release();
        _buffer = new char[bufferSize];
        memcpy( _buffer, rhs._buffer, sizeof(char)* bufferSize );
        return *this;
    }
    ~KTest( )
    {
        Release();
    }
    void Release()
    {
        if (_buffer)
        {
            delete[] _buffer;
            _buffer = nullptr;
        }
    }
};

void Test( KTest t )
{

}

void main()
{
    KTest   t;
    Test( t );
    KTest   t2;
    t2 = t;
}
