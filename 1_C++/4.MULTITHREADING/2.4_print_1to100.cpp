#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;
int a=0;
void printNumbers(int id) {
    //lock_guard<mutex> lock(mtx); // Automatically acquires and releases the lock
    mtx.lock();
    for (int i = 1; i <=50; ++i) {
        cout << "Thread " << id << ": " << a << endl;
        ++a;
    }
    mtx.unlock();
}

int main() {
    thread t1(printNumbers, 1);
    thread t2(printNumbers, 2);    
    t2.join();
    t1.join();
    cout<<a<<endl;
    return 0;
}
