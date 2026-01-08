#include <iostream>
#include <thread>
#include <shared_mutex>
#include <vector>
#include <atomic>
#include <chrono>

using namespace std;

const int SIZE = 10;  
int arr[SIZE];        // Shared array
shared_mutex rw_mutex;
atomic<bool> ready(false); // Flag to indicate writing is done

// Writer function: fills the array with numbers 1-10
void writer() {
    unique_lock<shared_mutex>lock(rw_mutex); // Exclusive write access
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
        this_thread::sleep_for(chrono::milliseconds(100)); // Simulate writing delay
    }
    cout << "Writer has finished writing.\n";
    ready.store(true, memory_order_release); // Notify readers that writing is done
}
// Reader function: reads the array once writing is complete
void reader(int reader_id) {
    while (!ready.load(memory_order_acquire)) {
        this_thread::yield(); // Wait until writer completes
    }
    
    shared_lock<shared_mutex> lock(rw_mutex); // Multiple readers allowed
    cout << "Reader " << reader_id << " reads: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
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

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
