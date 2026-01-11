#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
bool isOddTurn = true;

void printOdd() {
    for (int i = 1; i <= 10; i += 2) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return isOddTurn; });
        cout << i << " ";
        isOddTurn = false;
        cv.notify_one();
    }
}

void printEven() {
    for (int i = 2; i <= 10; i += 2) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !isOddTurn; });
        cout << i << " ";
        isOddTurn = true;
        cv.notify_one();
    }
}

int main() {
    thread t1(printOdd);
    thread t2(printEven);
    
    t1.join();
    t2.join();
    
    return 0;
}
