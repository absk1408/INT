#include <iostream>
using namespace std;

void counterFunction() {
    static int counter = 0;  // Static variable retains value across function calls
    counter++;  // Increment the value
    cout << "Counter: " << counter << endl;
}

int main() {
    counterFunction();  // Counter: 1
    counterFunction();  // Counter: 2
    counterFunction();  // Counter: 3
    //cout<<counter<<endl; still cant access here
    return 0;
}
