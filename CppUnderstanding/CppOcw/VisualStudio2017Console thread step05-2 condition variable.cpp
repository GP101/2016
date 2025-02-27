#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread()
{
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [] { return ready; });

    std::cout << "Worker thread processes\n";
    data += " after processing";

    // send data back to main()
    processed = true;
    std::cout << "Worker thread signals\n";

    // manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    lk.unlock();
    cv.notify_one();
}

int main()
{
    std::thread worker(worker_thread);

    data = "Example data";
    {
        std::lock_guard<std::mutex> lk(m);
        ready = true;
        std::cout << "main() signals\n";
    }
    cv.notify_one();

    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [] { return processed; });
    }
    std::cout << "Back in main(), data = " << data << '\n';

    worker.join();
}
