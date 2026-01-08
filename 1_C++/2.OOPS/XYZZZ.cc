#include <iostream>
using namespace std;

class Engine { int val;
public:
Engine(int a){
    val=a;

}
    void start() {
        cout << "Engine"<<val<<" started"<<endl;
    }
};

class Car {
private:
    Engine* engine;  // Car has an Engine
public:
    Car(Engine* c):engine(c){}
    void start(){
        engine->start();  // Delegate to Engine
        cout << "Car started.\n";
    }
};

int main() {
    Engine e(100);
    Car myCar(&e);
    myCar.start();
    return 0;
}
