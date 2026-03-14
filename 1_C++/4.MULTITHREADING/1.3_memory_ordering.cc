#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

atomic<int> flag(0);
int d= 0;

void writer() {
    d = 100;
    flag.store(1);  
}

void reader() {
    while(flag.load() == 0);
    cout << d << endl;
}

int main(){
    thread t1(writer);
    thread t2(reader);
    t1.join();t2.join();
    return 0;
}