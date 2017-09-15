#include <stdio.h>

template <class T> struct PTS
{
    enum
    {
        IsPointer = 0,
        IsPointerToDataMember = 0
    };
};//struct PTS

template <class T> struct PTS<T*>
{
    enum
    {
        IsPointer = 1,
        IsPointerToDataMember = 0
    };
};//struct PTS

template <class T, class U> struct PTS<T U::*>
{
    enum
    {
        IsPointer = 0,
        IsPointerToDataMember = 1
    };
};//struct PTS

struct S{};

int main()
{
    S       s;
    S*      pS;
    int     S::*ptm;

    printf_s("PTS<S>::IsPointer == %d PTS<S>::IsPointerToDataMember == %d\n"
        , PTS<S>::IsPointer, PTS<S>::IsPointerToDataMember);
    printf_s("PTS<S*>::IsPointer == %d PTS<S*>::IsPointerToDataMember == %d\n"
        , PTS<S*>::IsPointer, PTS<S*>::IsPointerToDataMember);
    printf_s("PTS<int S::*>::IsPointer == %d PTS"
        "<int S::*>::IsPointerToDataMember == %d\n"
        , PTS<int S::*>::IsPointer
        , PTS<int S::*>::IsPointerToDataMember);
}//main()
