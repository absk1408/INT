#include<iostream>
using namespace std;

void print(int* s) {
    cout << "Non-const version called: " << *s << endl;
}

void print(const int* s) {
    cout << "Const version called: " << *s << endl;
}

int main() {
    int a=100;
    int* p=&a;
    const int* b=&a;
    print(p);  // Calls non-const version
    print(b);  // Calls const version  

    //const function call only goes to const else gives errir

    return 0;   
}
