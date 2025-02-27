#include <string.h>
#include <stdio.h>
#include <thread>
#include <mutex>

char nextchar(const char* input)
{
    static int index = 0;
    static const char* pdata;
    if (input != nullptr) {
        index = 0;
        pdata = input;
    }
    else if (input == nullptr)
        index += 1;
    return pdata[index];
}

int main(void)
{
    char input[] = "hello world";
    char c = nextchar(input);
    while (c != 0) {
        printf("%c", c);
        c = nextchar(nullptr);
    }
}
