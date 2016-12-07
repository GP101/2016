#include <stdio.h>
#include <iostream>
#include <memory>
#include <time.h>

/*  @desc   random()
for (int i = 0; i < 10; ++i) {
float r = random(-1.f, +1.f);
printf("%g\r\n", r);
}//for */
float random(float fmin, float fmax)
{
    float f = (float)rand() / (float)RAND_MAX;
    return f * (fmax - fmin) + fmin;
}

struct true_type
{
    static const bool value = true;
};

struct false_type
{
    static const bool value = false;
};

template<typename T>   // primary template
struct is_void : false_type
{
};

template<>  // explicit specialization for T = void
struct is_void<void> : true_type
{
};

int main()
{
    // for any type T other than void, the 
    // class is derived from false_type
    std::cout << is_void<char>::value << '\n';

    // but when T is void, the class is derived
    // from true_type
    std::cout << is_void<void>::value << '\n';
}
