#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

once_flag flag;  // global flag used with call_once

void func() {
    cout << "Initialized once by thread: " << this_thread::get_id() << endl;
}
void worker() {
    call_once(flag, func);  // only one time func will execute
}
int main() {
    thread t1(worker);
    thread t2(worker);
    thread t3(worker);
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
