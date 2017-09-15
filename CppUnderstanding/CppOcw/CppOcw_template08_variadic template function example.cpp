#include <iostream>

void myprintf(const char *s)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                throw std::runtime_error("invalid format string: missing arguments");
            }
        }
        std::cout << *s++;
    }
}

template<typename T, typename... Args>
void myprintf(const char *s, T value, Args... args)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                std::cout << value;
                s += 2; // this only works on 2 characters format strings ( %d, %f, etc ). Fails miserably with %5.4f
                myprintf(s, args...); // call even when *s == 0 to detect extra arguments
                return;
            }
        }
        std::cout << *s++;
    }
}

void main()
{
    int i = 2;
    float f = 3.1f;
    myprintf("hello %% %i, %i\r\n", i, f);
}
