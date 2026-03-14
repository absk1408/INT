#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

atomic<int> x(0), y(0);
int r1, r2;

void t1() {
    x.store(1, memory_order_relaxed);
    r1 = y.load(memory_order_relaxed);
}

void t2() {
    y.store(1, memory_order_relaxed);
    r2 = x.load(memory_order_relaxed);
}

int main() {
    thread a(t1);
    thread b(t2);

    a.join();
    b.join();

    cout << r1 << " " << r2 << endl;
}   /*1 0
0 1
1 1
0 0   <-- surprising but possible*/