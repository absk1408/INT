#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
mutex m1, m2;
void worker(int id) {
    scoped_lock lock(m1,m2); // Deadlock-free locking of multiple mutexes
    for(int i=0;i<10;i++){
        cout<<"Thread:"<<id<<" "<<i<<endl;
    }
    cout << "Thread " << id << " is working!" << endl;
}
int main() {
    thread t1(worker, 1);
    thread t2(worker, 2);
    thread t3(worker,3);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
