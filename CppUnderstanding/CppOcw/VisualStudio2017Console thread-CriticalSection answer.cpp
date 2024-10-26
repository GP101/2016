#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>

std::atomic_int x;
std::atomic_int y;
std::mutex g_mutex;

void f1()
{
    while (true)
    {
        {
            std::lock_guard<std::mutex> lock(g_mutex);
            ++x;
            ++y;
        }
    }
}

void f2()
{
    while (true)
    {
        bool isLess = false;
        {
            std::lock_guard<std::mutex> lock(g_mutex);
            isLess = (x < y);
        }
        if (isLess)
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
