#include <atomic>
#include <thread>
#include <iostream>
using namespace std;
class Spinlock {
    atomic_flag flag = ATOMIC_FLAG_INIT;
    public:
    void lock_function() {
        //while (flag.test_and_set()); default: seq_cst
        while (flag.test_and_set(memory_order_acquire)) {
            // Spin-wait (busy loop)
        }
    }
    void unlock_function() {
        //flag.clear(); default:seq_cst
        flag.clear(memory_order_release);
    }
};

Spinlock spinlock;
int counter = 0;
void increment() {
    spinlock.lock_function();
    for (int i = 0; i < 1000; ++i) {
        ++counter;
    }
    spinlock.unlock_function();
}
int main() {
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout << "Counter: " << counter << endl;
    return 0;
}
