#include <iostream>
#include <string>
using namespace std;

int main() {
    string name = "Abhishek";
    name += " Yadav";
    cout << "Full Name: " << name << endl;
    
    if (name.find("Yadav") != string::npos) {
        cout << "Last name found!" << endl;
    }

    name.replace(0, 8, "Mr. A");
    cout << "Modified: " << name << endl;

    return 0;
}
