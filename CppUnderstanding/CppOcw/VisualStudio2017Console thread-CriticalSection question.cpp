#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>

std::atomic_int x;
std::atomic_int y;

void f1()
{
    while (true)
    {
        ++x;
        ++y;
    }
}

void f2()
{
    while (true)
    {
        if(x < y)
        {
            std::cout << "error" << std::endl;
        }
    }
}

int main()
{
    x = 0;
    y = 0;

    std::thread t1(f1);
    std::thread t2(f2);

    t1.join();
    t2.join();
}
