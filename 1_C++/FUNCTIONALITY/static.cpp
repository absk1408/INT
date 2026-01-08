#include <iostream>
using namespace std;

int globalVar = 10;  // Stored in Data Segment (.data)
static int staticVar=100;
void function() {
    int localVar = 5;  // Stored in Stack
    static int staticVar = 20;  // Stored in Data Segment (.data)
    
    cout << "Local Variable (Stack): " << localVar << endl;
    cout << "Static Variable (Data Segment): " << staticVar << endl;
    cout << "in func " << &staticVar << endl;
}

int main() {
    function();
    function(); // staticVar retains its value
    cout<<globalVar<<" "<<staticVar<<&staticVar<<endl;
    return 0;
}