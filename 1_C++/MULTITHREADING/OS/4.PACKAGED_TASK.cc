#include <iostream>
#include <thread>
#include <future>

using namespace std;

// Function to compute the sum
int func(int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += i;
    }
    return result;  // Directly return the result
}

int main() {
    // Create a packaged_task that wraps the func function
    packaged_task<int(int)> task(func);

    // Get the future associated with the task
    future<int> sumfuture = task.get_future();

    int val = 10;

    // Launch a thread to execute the task
    thread t1(move(task), val);

    // Retrieve and print the result
    cout << sumfuture.get() << endl;

    // Join the thread
    t1.join();

    return 0;
}
