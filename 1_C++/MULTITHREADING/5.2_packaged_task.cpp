#include <iostream>
#include <thread>
#include <future>
using namespace std;

int compute(int x) {
    return x * x;
}

int main() {
    packaged_task<int(int)> task(compute); // Wrap the function
    future<int> result = task.get_future();

    thread t(move(task), 5); // Launch the task in a thread
    t.join();

    cout << "Result: " << result.get() << endl; // Retrieve the result
    return 0;
}
