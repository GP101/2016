#include <utility>

void IntTest(const int& x)
{
    printf("l-value\r\n");
}

void IntTest(int&& x)
{
    printf("r-value\r\n");
}

// function template taking rvalue reference to deduced type:
template <class T> void Test(T&& x)
{
    //IntTest(std::forward<T>(x));
    IntTest(x);
}

void main()
{
    int a;
    Test(a);
    Test(0);
}