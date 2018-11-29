///////////////////////////////////////////////////////////////////////////////
//
//  MallocAlloc.h
//
//  Malloc-based allocator. Uses standard malloc and free.
//
//  Copyright ?2002 Pete Isensee (PKIsensee@msn.com).
//  All rights reserved worldwide.
//
//  Permission to copy, modify, reproduce or redistribute this source code is
//  granted provided the above copyright notice is retained in the resulting 
//  source code.
// 
//  This software is provided "as is" and without any express or implied
//  warranties.
//
///////////////////////////////////////////////////////////////////////////////

#if !defined( MALLOC_ALLOCATOR_H )
#define MALLOC_ALLOCATOR_H

#include <memory>
#include <limits>

///////////////////////////////////////////////////////////////////////////////
//
// MallocAlloc

template <typename T>
class MallocAlloc
{
public:

    // Typedefs
    typedef size_t    size_type;
    typedef ptrdiff_t difference_type;
    typedef T*        pointer;
    typedef const T*  const_pointer;
    typedef T&        reference;
    typedef const T&  const_reference;
    typedef T         value_type;

public:

    // Constructors
    MallocAlloc() throw()
    {
    }

    MallocAlloc( const MallocAlloc& ) throw()
    {
    }

    template <typename U>
    MallocAlloc( const MallocAlloc<U>& ) throw()
    {
    }

    MallocAlloc& operator=( const MallocAlloc& )
    {
        return *this;
    }

    // Destructor
    ~MallocAlloc() throw()
    {
    }

    // Utility functions
    pointer address( reference r ) const
    {
        return &r;
    }

    const_pointer address( const_reference c ) const
    {
        return &c;
    }

    size_type max_size() const
    {
        return size_type(-1) / sizeof(T);
    }

    // In-place construction
    void construct( pointer p, const_reference c )
    {
        // placement new operator
        new( reinterpret_cast<void*>(p) ) T(c);
    }

    // In-place destruction
    void destroy( pointer p )
    {
        // call destructor directly
        (p)->~T();
    }

    // Rebind to allocators of other types
    template <typename U>
    struct rebind
    {
        typedef MallocAlloc<U> other;
    };

    // Allocate raw memory
    pointer allocate( size_type n, const void* = NULL )
    {
        void* p = malloc( n * sizeof(T) );
        if( p == NULL )
            throw std::bad_alloc();
        return pointer(p);
    }

    // Free raw memory.
    // Note that C++ standard defines this function as
    // deallocate( pointer p, size_type). Because Visual C++ 6.0
    // compiler doesn't support template rebind, Dinkumware uses
    // void* hack.
    void deallocate( void* p, size_type )
    {
        // assert( p != NULL );
        // The standard states that p must not be NULL. However, some
        // STL implementations fail this requirement, so the check must
        // be made here.
        if( p == NULL )
            return;
        free( p );
    }

private:

    // No data

}; // end of MallocAlloc

// Comparison
template <typename T1, typename T2>
bool operator==( const MallocAlloc<T1>&,
                 const MallocAlloc<T2>& ) throw()
{
    return true;
}

template <typename T1, typename T2>
bool operator!=( const MallocAlloc<T1>&,
                 const MallocAlloc<T2>& ) throw()
{
    return false;
}

#endif // MALLOC_ALLOCATOR_H

///////////////////////////////////////////////////////////////////////////////
