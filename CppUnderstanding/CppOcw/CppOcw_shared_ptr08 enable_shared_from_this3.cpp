#include <stdio.h>
#include <algorithm>

template<typename T>
class enable_shared_from_this
{
protected:
    //std::weak_ptr<T>    weskSelf;

public:
    //shared_ptr<T> shared_from_this()
    //{
    //    return weskSelf.lock();
    //}
};

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
    T*          px;
    int*        pn;
public:
    explicit shared_ptr( T* p = nullptr ) : px( p ), pn( nullptr )
    {
        if (px != nullptr)
        {
            pn = new int;
            *pn = 1;
        }//if
        if (std::is_base_of<enable_shared_from_this<T>, T>::value) {
            //_initialize_weak_ptr( *this );
            printf( "_initialize_weak_ptr\r\n" );
        }
    }
    shared_ptr( const shared_ptr<T>& rhs )
    {
        px = rhs.px;
        pn = rhs.pn;
        if (px != nullptr)
        {
            *pn += 1;
        }
    }
    ~shared_ptr()
    {
        release();
    }
    void release()
    {
        if (px != nullptr && *pn >= 1)
        {
            *pn -= 1; // decrease reference counter
            if (*pn == 0)
            {
                delete px;
                delete pn;
            }
        }
        px = nullptr;
        pn = nullptr;
    }
    void swap( shared_ptr<T>& rhs )
    {
        std::swap( px, rhs.px );
        std::swap( pn, rhs.pn );
    }
    shared_ptr<T>& operator=( const shared_ptr<T>& rhs )
    {
        this_type( rhs ).swap( *this ); // copy-and-swap idiom
        return *this;
    }
    void reset( T* p = nullptr )
    {
        this_type( p ).swap( *this );
    }
    int use_count() const
    {
        return *pn;
    }
    reference operator*()
    {
        return *px;
    }
    T* operator->()
    {
        return px;
    }
    void unspecified_bool()
    {
    }
    typedef void ( shared_ptr::*unspecified_bool_type )( );
    operator unspecified_bool_type()
    {
        return px != nullptr ? &shared_ptr::unspecified_bool : nullptr;
    }
};//class shared_ptr

class KTest : public enable_shared_from_this<KTest>
{
public:
    KTest()
    {
    }
};

void main()
{
    shared_ptr<KTest>  sp;
    sp.reset( new KTest() );
}//int main()
