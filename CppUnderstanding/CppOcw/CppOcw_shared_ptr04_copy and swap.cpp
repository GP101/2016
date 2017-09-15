#include <stdio.h>
#include <algorithm>

template<typename T>
struct shared_ptr_traits
{
    typedef T&  reference;
};

template<>
struct shared_ptr_traits<void>
{
    typedef void   reference;
};

template<typename T>
class shared_ptr
{
public:
    typedef shared_ptr<T>   this_type;
    typedef T               value_type;
    typedef T*              pointer;
    typedef typename shared_ptr_traits<T>::reference
                            reference;
private:
};//class shared_ptr

class KTest
{
public:
    typedef KTest   this_type;
private:
    int*        px;
public:
    KTest( int* p ) : px( p ) {}
    KTest( const KTest& rhs )
    {
        px = new int;
        *px = *rhs.px; // copy
    }
    KTest& operator=( const KTest& rhs )
    {
        //release();
        //px = new int;
        //*px = *rhs.px; // copy

        this_type( rhs ).swap( *this ); // copy-and-swap idiom

        return *this;
    }
    ~KTest()
    {
        release();
    }
    void release()
    {
        if( px != nullptr )
        {
            delete px;
            px = nullptr;
        }
    }
    int GetData() const
    {
        return *px;
    }
    void swap( KTest& rhs )
    {
        std::swap( px, rhs.px ); // non-throwing swap
    }
};

void main()
{
    KTest   t( new int( 2 ) );
    KTest   u( new int( 3 ) );

    u = t; // u.operator=(t)
    printf( "%i\r\n", u.GetData() );
}//int main()
