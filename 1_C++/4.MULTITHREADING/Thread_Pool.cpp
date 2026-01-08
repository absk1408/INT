#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;
class ThreadPool {
    vector<thread> workers;
    queue<function<void()>> tasks;
    mutex mtx;
    condition_variable cv;
    bool stop;
public:
    ThreadPool(size_t threads) : stop(false) {
        for (size_t i = 0; i < threads; ++i) {
            workers.emplace_back([this]() {
                while (true) {
                    function<void()> task;
                    {
                        unique_lock<mutex> lock(mtx);
                        cv.wait(lock, [this]() { return stop || !tasks.empty(); });
                        if (stop && tasks.empty())
                            return;
                        task = move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
            });
        }
    }
    template <class F>
    void enqueue(F&& f) {
        {
            lock_guard<mutex> lock(mtx);
            tasks.emplace(forward<F>(f)); //can remove forward
        }
        cv.notify_one();
    }
    ~ThreadPool() {
        {
            lock_guard<mutex> lock(mtx);
            stop = true;
        }
        cv.notify_all();
        for (thread& worker : workers)
            worker.join();
    }
};
void exampleTask(int id) {
    cout << "Task " << id << " is running" << endl;
}
int main() {
    ThreadPool pool(3); // 3 threads in the pool
    for (int i = 1; i <= 5; ++i) {
        pool.enqueue([i]() { exampleTask(i); });
    }
    return 0;
}
