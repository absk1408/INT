#include <iostream>
#include<exception>
#include<stdexcept>
using namespace std;
class Test {
    string name;
public:
    Test(string n) : name(n) {
        cout << "Constructing " << name << endl;
    }
    
    ~Test() {
        cout << "Destructing " << name << endl;
    }
};

void functionC() {
    Test objC("C");
    throw runtime_error("Exception in functionC");  // Exception thrown here
}
void functionB() {
    Test objB("B");
    functionC();  // Calls functionC, which throws an exception
}
void functionA() {
    Test objA("A");
    try {      
        functionB();
    }   //catch always follow where try is defined
    catch (const exception &e) {  // if no catch block found it will search and terminate in the main();
        cout << "Caught exception: " << e.what() << endl;
    }
    catch (...) {  //universal catch block
    // handles anything thrown
    }
} // best pair runtime_error(" ") => catch(cont exception &e) =>cout<<e.what;   or use catch(...) if unknown
int main() {
    functionA();
    cout<<"main over"<<endl;
    return 0;
}
