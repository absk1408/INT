#include <iostream>
using namespace std;
class Base{
public:
    int f(int i){
        cout << "f(int): ";
        return i+3;
    }
    int f(double d){
        cout << "f(dob): ";
        return d+6;
        
    }
};
class Derived : public Base{

};
int main(){
    Derived* dp = new Derived;
    cout << dp->f(3) << '\n';
    cout << dp->f(3.3) << '\n';
    delete dp;
    return 0;
}
