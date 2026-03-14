#include <stdio.h>
#include <iostream>
#include <memory>
#include <time.h>

struct true_type
{
    static const bool value = true;
};

struct false_type
{
    static const bool value = false;
};

template<typename T>
struct is_void : false_type
{
};

template<> // full template specialization
struct is_void<void> : true_type
{
};

template<typename T>
struct is_pointer : false_type
{
};

template<typename T> // partial template specialization
struct is_pointer<T*> : true_type
{
};

template<typename T>
struct is_pointer<const T*> : true_type
{
};

template<typename T>
void Test(T value) {
    if (is_pointer<T>::value)
    {
        printf("Something for pointer type\n");
    }
    printf("Test for T\n");
}

int main()
{
    std::cout << is_void<char>::value << '\n'; // 0
    std::cout << is_void<void>::value << '\n'; // 1

    Test(1);
    Test("Hello");

    /**
        0
        1
        Test for T
        Something for pointer type
        Test for T
    */
    return 0;
}