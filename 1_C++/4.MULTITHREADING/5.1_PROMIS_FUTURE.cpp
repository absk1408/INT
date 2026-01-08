#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;

// Function executed by the producer thread
void calculateSquare(promise<int> promise, int number) {
    int result = number * number;
    this_thread::sleep_for(chrono::seconds(2)); // Simulate some work
    promise.set_value(result); // Set the result of the computation
}

int main() {
    // Create a promise object to hold the result
    promise<int> promise;
    // Get the associated future object
    future<int> future = promise.get_future();

    // Launch a producer thread to calculate the square
    thread producer(calculateSquare, move(promise), 5);

    // Main thread can do other work here if needed
    cout << "Waiting for the result..." << endl;

    // Get the result from the future (this will block until the result is available)
    int result = future.get();
    cout << "The square is: " << result << endl;

    // Ensure the producer thread completes
    producer.join();
    
    return 0;
}
