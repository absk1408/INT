#include <iostream>
#include <thread>
#include <shared_mutex>
#include <vector>
#include <atomic>
#include <chrono>

using namespace std;

const int SIZE = 10;  
int arr[SIZE];        // Shared array accessed by writer and readers
shared_mutex rw_mutex; // Reader–writer mutex:
                       // - exclusive lock for writer
                       // - shared lock for readers
atomic<bool> ready(false); // Atomic flag to indicate writer has finished

// Writer function: fills the array with numbers 1-10
void writer() {
    unique_lock<shared_mutex>lock(rw_mutex); // Exclusive lock: blocks all readers and writers

    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1; // Write data safely under exclusive lock
        this_thread::sleep_for(chrono::milliseconds(100)); // Simulate slow write
    }

    cout << "Writer has finished writing.\n";

    // Release-store ensures all writes to arr[]
    // happen-before readers observe ready == true
    ready.store(true, memory_order_release);
}

// Reader function: reads the array after writer completes
void reader(int reader_id) {

    // Spin until writer signals completion
    // acquire-load pairs with writer's release-store
    while (!ready.load(memory_order_acquire)) {
        this_thread::yield(); // Avoid aggressive busy spinning
    }
    
    shared_lock<shared_mutex> lock(rw_mutex); // Shared lock: multiple readers allowed

    cout << "Reader " << reader_id << " reads: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " "; // Safe read under shared lock
    }
    cout << endl;
}

int main() {
    vector<thread> threads;

    // Start the writer thread
    threads.emplace_back(writer);

    // Start multiple reader threads
    for (int i = 1; i <= 3; i++) {
        threads.emplace_back(reader, i);
    }

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
