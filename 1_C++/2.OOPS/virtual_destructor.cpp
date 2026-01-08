// CPP program without virtual destructor 
// causing undefined behavior
#include <iostream>

using namespace std;

class base {
public:
	base()	 
	{ cout << "Constructing base\n"; }
	virtual ~base()
	{ cout<< "Destructing base\n"; }	 
};

class derived: public base {
public:
	derived()	 
	{ cout << "Constructing derived\n"; }
	~derived()
	{ cout << "Destructing derived\n"; }
};

int main(){
derived d; 
base *b = &d;  // virtual keyword not required casuse derived created on stack

base* b1=new derived();
delete b1;
return 0;

}
