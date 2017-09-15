#include <stdio.h>

void Test()
{
    static int g_int = 0;
    g_int += 1;
    printf( "%i\r\n", g_int );
}

template<typename T>
class KFooWrapper
{

public:
    static T& Instance()
    {
        return KFoo::Access();
    }

    class KFoo
    {
    public:
        KFoo()
        {
            printf( "%s\r\n", __FUNCTION__ );
            Access();
        }
        void Dummy()
        {
        }
        static T& Access()
        {
            static T wrapper;
            //ms_foo.Dummy();
            return wrapper;
        }
        static KFoo     ms_foo;
    };
};

template<typename T>
typename KFooWrapper<T>::KFoo     KFooWrapper<T>::KFoo::ms_foo;

class KTest : public KFooWrapper<KTest>
{
public:
    KTest()
    {
        printf( "%s\r\n", __FUNCTION__ );
    }
};

void main()
{
    printf( "hello\r\n" );
    KTest::Instance();
}
