#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

const int g_numLoop = 10;
int g_value = 0;
std::mutex  g_m;
std::queue<int>     g_queue;

void WorkerThread1(int param)
{
    for (int i = 0; i < g_numLoop; ++i) {
        g_m.lock();
        g_queue.push(i);
        g_m.unlock();
    }
}

void WorkerThread2(int param)
{
    g_m.lock();
    while(!g_queue.empty()) {
        int packet = g_queue.front();
        g_queue.pop();
        printf("packet %i\r\n", packet);
    }
    g_m.unlock();
}

int main()
{
    std::thread worker1(WorkerThread1, 1);
    std::thread worker2(WorkerThread2, 11);

    worker1.join();
    worker2.join();
    std::cout << g_value << std::endl;
}
