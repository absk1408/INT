#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;
class ThreadPool { // Thread Pool Class
    vector<thread> workers;                 // Worker threads
    queue<function<void()>> tasks;         // Task queue
    mutex mtx;                             // Mutex for synchronization
    condition_variable cv;                 // Condition variable for notification
    bool stop;                             // Flag to signal stopping
    void workerFunction() {  // Worker thread function
        while (true) {
            function<void()> task;
            {
                unique_lock<mutex> lock(mtx);
                cv.wait(lock, [this]() { return stop || !tasks.empty(); });
                if (stop && tasks.empty()) {
                    return; // Exit the thread
                }
                task = move(tasks.front());
                tasks.pop();
            }
            task(); // Execute the task
        }
    }
    public:  // Constructor
    ThreadPool(size_t threadCount) : stop(false) {
        for (size_t i = 0; i < threadCount; ++i) {
            workers.emplace_back(&ThreadPool::workerFunction, this);
        }
    }
    // Enqueue a new task
    void enqueue(function<void()> task) {
        {
            lock_guard<mutex> lock(mtx);
            tasks.push(move(task));
        }
        cv.notify_one(); // Notify a worker thread
    }
    ~ThreadPool() {   // Destructor
        {
            lock_guard<mutex> lock(mtx);
            stop = true; // Set stop flag
        }
        cv.notify_all(); // Notify all threads to stop
        for (thread& worker : workers) {
            worker.join(); // Wait for all threads to finish
        }
    }
};
mutex coutmutex;
void exampleTask(int id) { // Example Task Function
    lock_guard<mutex> lock(coutmutex);
    cout << "Task " << id << " is running" << endl;
}
int main() { // Main Function
    ThreadPool pool(3); // Create a thread pool with 3 threads
    // Add tasks to the pool
    for (int i = 1; i <= 5; ++i) {
        pool.enqueue([id = i]() { exampleTask(id); }); // Use a wrapper function to add tasks
    }
    return 0;
}
