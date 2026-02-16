#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//class derived;   
/*   derived is only forward declared (incomplete type)
The compiler knows:
“A class named derived exists”
But it does NOT know:
What members it has
That data exists 
*/


class derived {
public:
    int data;
    derived(int data) {
        this->data = data;
    }
};

class base {
public:
    vector<derived*> v;

    void add_o(derived* obj) { 
        v.push_back(obj);
    }

    void show() {
        vector<derived*>::iterator it;
        for (it = v.begin(); it != v.end(); ++it) {
            cout << (*it)->data << endl;
        }
    }
};


int main() {
    derived d1(100);
    derived d2(200);
    derived d3(300);
    
    base b1;
    b1.add_o(&d1);
    b1.add_o(&d2);
    b1.add_o(&d3);
    
    b1.show();
    
    return 0;
}
