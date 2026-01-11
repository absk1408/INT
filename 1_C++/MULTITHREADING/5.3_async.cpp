#include <iostream>
#include <future>
using namespace std;

int fetch_data(int id) {
    cout << "Data fetched for id: " << id << "\n";
    return id * 10; // Simulated result
}

int main() {
    auto future1 = async(launch::async, fetch_data, 1);
    auto future2 = async(launch::deferred, fetch_data, 2);
    // some work...

    int result1 = future1.get();
    int result2 = future2.get();

    return 0;
}
