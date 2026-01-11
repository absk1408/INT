#include <iostream> //C++20
#include <thread>
#include <latch>
using namespace std;
latch syncPoint(3);
void worker(int id) {
    cout << "Worker " << id << " waiting..." << endl;
    syncPoint.count_down(); // Decrement the latch
    syncPoint.wait();       // Wait until the latch is released
    cout << "Worker " << id << " proceeding!" << endl;
}
int main() {
    thread t1(worker, 1);
    thread t2(worker, 2);
    thread t3(worker, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
