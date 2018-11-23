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
    ~KTest()
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
    Test( t ); // crash
}
