#include <iostream>
#include <thread>
using namespace std;

thread_local int counter = 0;

void incrementCounter() {
    counter++;
    cout << "Thread " << this_thread::get_id() << ": Counter = " << counter << endl;
}

int main() {
    thread t1(incrementCounter);
    thread t2(incrementCounter);

    t1.join();
    t2.join();

    return 0;
}
