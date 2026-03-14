#include <iostream>
using namespace std;

// Strategy Interface
class Strategy {
public:
    virtual void execute() = 0;
    virtual ~Strategy() {}
};

// Concrete Strategies
class ConcreteStrategyA : public Strategy {
public:
    void execute() override {
        cout << "Executing Strategy A" << endl;
    }
};

class ConcreteStrategyB : public Strategy {
public:
    void execute() override {
        cout << "Executing Strategy B" << endl;
    }
};

// Context
class Context {
    Strategy* strategy;
public:
    Context(Strategy* s) : strategy(s) {}
    void setStrategy(Strategy* s) {
        strategy = s;
    }
    void execute() {
        strategy->execute();
    }
};

int main() {
    ConcreteStrategyA a;
    ConcreteStrategyB b;
    Context context(&a);
    
    context.execute();  // Uses Strategy A
    context.setStrategy(&b);
    context.execute();  // Switches to Strategy B
    
    return 0;
}
