#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
//condition_variable cv;
int counter = 1; // Shared counter

void printOdd() {
    while (counter <= 10) {
        {
            lock_guard<mutex> lock(mtx);
            if (counter % 2 != 0) {
                 cout << "Thread 1 (Odd): " << counter << endl;
                counter++;   
            }
        }
        this_thread::yield(); //Yield to let the other thread proceed
    }
}

void printEven() {
    while (counter <= 10) {
        {
            lock_guard<mutex> lock(mtx);
            if (counter % 2 == 0) {
                 cout << "Thread 2 (Even): " << counter << endl;
                counter++;
            }
        }
        this_thread::yield(); //Yield to let the other thread proceed
    }
}

int main() {
    thread t1(printOdd);  //Thread to print odd numbers
    thread t2(printEven); //Thread to print even numbers

    t1.join();
    t2.join();

    return 0;
}
