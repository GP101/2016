#include <string.h>
#include <stdio.h>
#include <thread>
#include <mutex>

char nextchar(const char* input)
{
    thread_local int index = 0;
    thread_local const char* pdata;
    if (input != nullptr) {
        index = 0;
        pdata = input;
    }
    else if (input == nullptr)
        index += 1;
    return pdata[index];
}

void WorkerThread1(int param)
{
    char input[] = "hello world";
    char c = nextchar(input);
    while (c != 0) {
        printf("%c", c);
        c = nextchar(nullptr);
    }
}

void WorkerThread2(int param)
{
    char input[] = "wonderful earth";
    char c = nextchar(input);
    while (c != 0) {
        printf("%c", c);
        c = nextchar(nullptr);
    }
}

int main(void)
{
    std::thread worker1(WorkerThread1, 1);
    std::thread worker2(WorkerThread2, 11);

    worker1.join();
    worker2.join();
}
