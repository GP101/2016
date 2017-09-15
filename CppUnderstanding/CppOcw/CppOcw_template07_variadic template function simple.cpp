#include <stdio.h>

void Process(int i)
{
    printf("%i\r\n",i);
}

void Process(float f)
{
    printf("%g\r\n",f);
}

void Process(const char* s)
{
    printf("%s\r\n",s);
}

void Func() {} // termination version

template<typename Arg1, typename... Args>
void Func(const Arg1& arg1, const Args&... args)
{
    Process(arg1);
    Func(args...); // note: arg1 does not appear here!
}

void main()
{
    Func( 2, 3.1f, "hello", 4);
}
