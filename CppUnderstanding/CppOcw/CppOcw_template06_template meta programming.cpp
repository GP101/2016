#include <stdio.h>

unsigned int Factorial(unsigned int n) {
    return n == 0 ? 1 : n * Factorial(n - 1);
}

template <unsigned int n>
struct KFactorial
{
    enum { value = n * KFactorial<n - 1>::value };
};

template <>
struct KFactorial<0>
{
    enum { value = 1 };
};

template <class DERIVED>
struct KBase
{
    void Interface()
    {
        // ...
        static_cast<DERIVED*>(this)->Implementation();
        // ...
    }
};

struct KDerived : KBase<KDerived>
{
    void Implementation()
    {
        printf("KDerived::Implementation()\r\n");
    }
};

void main()
{
    printf("%i\r\n", Factorial(5));
    printf("%i\r\n", KFactorial<5>::value );

    KDerived    a;
    a.Interface();
}//main()
