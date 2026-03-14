#include <stdio.h>

template<typename T>
void Test(T value) {
    printf("Test for T\n");
}

// full template specialization
template<>
void Test(const char* value) {
    printf("Test for char*\n");
}

int main()
{
    Test(1);
    Test("Hello");
}
