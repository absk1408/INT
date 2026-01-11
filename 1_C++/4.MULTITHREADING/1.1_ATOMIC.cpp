#include <atomic>
#include <thread>
#include <iostream>
using namespace std;

atomic<int> counter(0);

void increment(int id) {
    for (int i = 0; i < 100; ++i){
        counter.fetch_add(1);  //complete RMW at a time  //internally: counter.fetch_add(1, memory_order_seq_cst);  
        cout<<"id:"<<id<<" "<<counter<<endl;
    }
}
int main() {
    thread t1(increment,1);
    thread t2(increment,2);
    t1.join();
    t2.join();

    cout << "Counter: " << counter << endl;  // Always 2000
    return 0;
}
