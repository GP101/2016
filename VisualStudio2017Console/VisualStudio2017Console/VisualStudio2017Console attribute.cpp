#include <stdio.h>

[[nodiscard]]
int foo(int i) { return i * i; }

[[deprecated]]
void Test() { printf("test\r\n"); }

struct A
{
    // also for __declspec(deprecated)
    [[deprecated]] typedef int inttype;
};

int main()
{
    A::inttype a = 0; // C4996 'A::inttype': was declared deprecated

    foo(42); //warning C4834: discarding return value of function with 'nodiscard' attribute
    Test(); // error c4996: 'Test': was declared deprecated
    return 0;
}
