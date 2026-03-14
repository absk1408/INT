#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4};

    auto it = v.end();
    cout << *(it-1) << endl;   // OK
     cout << *it << endl;   // ❌ UB// v.end() is always a undefinded behaviour.
    

    v.erase(it);               // ❌ UB
}
