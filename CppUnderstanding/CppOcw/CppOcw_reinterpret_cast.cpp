#include <stdio.h>

class KTest
{

};

class KHello
{
};

void Test2(unsigned int i) {
    printf("%i\n", i);
}

void Test(void* p) {
    Test2((unsigned int)(p));
}


int main()
{
    unsigned int i = 12;
    Test((void*)i);

    KTest* pTest = nullptr;
    KHello* pHello = nullptr;

    //pTest = static_cast<KTest*>(pHello); // compile time error for non related types.
    pTest = reinterpret_cast<KTest*>(pHello); // dangerous, but no problem.
    if (pTest != nullptr)
    {
    }//if
}//main()
