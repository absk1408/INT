#include <iostream>
#include <thread>
#include <atomic>
using namespace std;
atomic<bool> flag = false;
int value = 0;
void writer() {
    value = 100;  // Step 1: write data
    flag.store(true, memory_order_release);  // Step 2: signal with release
}
void reader() {
    while (!flag.load(memory_order_acquire)) {
        // SPIN LOCK...wait until the flag is true
        this_thread::yield();
    }
    // Safe to read value
    cout << "Reader sees value: " << value << endl;
}

int main() {
    thread t1(writer);
    thread t2(reader);
    t1.join();
    t2.join();
    return 0;
}
