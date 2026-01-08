#include <iostream>
using namespace std;

class Test {
private:
    int x;
public:
    // Parameterized constructor only
    Test(){
        cout<<"default called"<<endl;
    }
    Test(int val) {
        x = val;
        cout << "Parameterized constructor called. x = " << x << endl;
    }

    // Display function
    void display() {
        cout << "Value of x: " << x << endl;
    }
};

int main() {
    Test obj = Test(10);  // No default constructor, only parameterized constructor is called
    obj.display(); // x = 10

    Test obj2=Test();
    obj2.display();

    return 0;
}
