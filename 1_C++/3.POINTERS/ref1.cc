#include <iostream>
using namespace std;

int& getReference() {
    static int x = 10; //make it static or else it will give error
    return x;
}

int main() {
    //int &ref = getReference();
    cout<<getReference()<<endl;
   // cout << ref;
    return 0;
}
