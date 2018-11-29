#include <iostream>
#include <iterator>

template<typename T>
class KType
{
public:
    template <typename U>
    struct rebind
    {
        typedef KType<U> other;
    };//struct rebind

    KType(){}
    KType( const KType& ) {}
    template <typename U>
    KType( const KType<U>& ) {}

    int size() { return sizeof(T); }
};//class KType

template<typename T, typename TALLOC=KType<T> >
class KTest
{
public:
    typedef T   value_type;
    struct _Node
    {
        value_type  _data1;
        value_type  _data2;
        _Node*      _next;
    };//struct _Node

    KTest(){}
    void PrintNodeSize()
    {
        TALLOC a;
        TALLOC::rebind<_Node>::other    allocator(a);
        std::cout << allocator.size() << std::endl;
    }
};//class KTest

void main()
{
    KTest<int>  t;
    t.PrintNodeSize();
/*
12
Press any key to continue
*/
}//main()
