#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

#define synchronized( statement_ ) \
    if (int iBlockScope = 0) {} \
    else \
    for (std::lock_guard<std::mutex> mtxHelper(statement_); iBlockScope == 0; iBlockScope = 1)

const int g_numLoop = 100000;
int g_value = 0;
std::mutex  g_m;

void WorkerThread1(int param)
{
    for (int i = 0; i < g_numLoop; ++i) {
        std::lock_guard<std::mutex> lock(g_m);
        g_value += 1;
    }
}

void WorkerThread2(int param)
{
    for (int i = 0; i < g_numLoop; ++i) {
        std::lock_guard<std::mutex> lock(g_m);
        g_value -= 1;
    }
}

int main()
{
    std::thread worker1(WorkerThread1, 1);
    std::thread worker2(WorkerThread2, 11);

    worker1.join();
    worker2.join();
    std::cout << g_value << std::endl;
}
