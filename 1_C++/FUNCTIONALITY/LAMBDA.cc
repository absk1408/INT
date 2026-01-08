#include <iostream>

using namespace std;
int main(){
    int a=100;int b=200;
    auto lam=[=]() mutable {cout<<(++a+(b))<<endl;};
    lam();
    cout<<a<<" "<<b<<endl;
}

/*
int main() {
    int a = 10, b = 20;

    auto sum = [=]() { cout << "Sum: " << (a + b) << endl; };

    sum(); // Uses values of a and b

    return 0;
}
*/

/*int main() {
    // Simple lambda expression
    auto greet = []() { cout << "Hello, Lambda!" << endl; };
    // Calling the lambda function
    greet();

    return 0;
}
*/