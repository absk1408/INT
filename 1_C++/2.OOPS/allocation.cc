//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
//

class Example {
public:
    int x;
    char y;
};

int main() {
    Example* obj1 = new Example;    // No parentheses -> Garbage values //indeterminate values  //default intialization
    Example* obj2 = new Example{};  // Parentheses -> Zero initialization   //value initialization

    cout << "Without (): " << obj1->x << ", " << obj1->y << endl; // Garbage
    cout << "With (): " << obj2->x << ", " << obj2->y << endl;   // 0, '\0'
    
    Example obj_stack;
    cout<<obj_stack.x<<" "<<obj_stack.y<<"."<<endl;  //indeterminate values

    // static Example obj_static;  //➡️ It would be zero-initialized automatically.

    delete obj1;
    delete obj2;
    return 0;
}
