#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

const int g_numLoop = 10;
int g_value = 0;
std::mutex  g_m;
std::condition_variable cv;
bool g_ready1 = false;
bool g_ready2 = false;

void WorkerThread1(int param)
{
    for (int i = 0; i < g_numLoop; ++i) {
        g_value += 1;
        std::cout << g_value
            << ", id=" << std::this_thread::get_id() << std::endl;
        {
            std::unique_lock<std::mutex> lock(g_m);
            cv.wait(lock, []()->bool {return g_ready2; });
            g_ready2 = false;
        }
        g_ready1 = true;
        cv.notify_one();
    }
}

void WorkerThread2(int param)
{
    for (int i = 0; i < g_numLoop; ++i) {
        g_value += 1;
        std::cout << g_value
            << ", id=" << std::this_thread::get_id() << std::endl;
        {
            std::unique_lock<std::mutex> lock(g_m);
            cv.wait(lock, []()->bool {return g_ready1; });
            g_ready1 = false;
        }
        g_ready2 = true;
        cv.notify_one();
    }
}

int main()
{
    std::thread worker1(WorkerThread1, 1);
    std::thread worker2(WorkerThread2, 11);

    worker1.join();
    worker2.join();
}
