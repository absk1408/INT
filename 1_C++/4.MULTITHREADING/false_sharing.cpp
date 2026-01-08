//dont show false result but degrade the performance
#include <iostream>
#include <thread>
using namespace std;

struct Data {
    int x;
    int y;
};
// struct Data {
//     alignas(64) int x; // Align on cache line boundary
//     alignas(64) int y;
// };
Data shared;
void threadFuncX() {
    for (int i = 0; i < 100000000; ++i)
        shared.x++;
}
void threadFuncY() {
    for (int i = 0; i < 1000000000; ++i)
        shared.y++;
}
int main() {
    thread t1(threadFuncX);
    thread t2(threadFuncY);
    t1.join();
    t2.join();
    cout << "x: " << shared.x << ", y: " << shared.y << endl;
    return 0;
}
