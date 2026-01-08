// https://www.go4expert.com/articles/virtual-table-vptr-t16544/
#include<iostream>
using namespace std;
class Base  
 {  
 public:  
 Base(){
    cout<<"base created"<<endl;
 }
    void function1() {cout<<"Base :: function1()\n";}
    void function2() {cout<<"Base :: function2()\n";}
    void funtion5(){cout<<"base : function3"<<endl;}
    ~Base(){cout<<"base destructor"<<endl;}
};  
   
class Der1: public Base  {  
public:  
   //~D1(){cout<<"derived destructor"<<endl;};
   Der1(){
    cout<<"Der1 created"<<endl;
 }
    virtual void function1() { 
        cout<<"D1 :: function1()\n";
    }
    void function3(){
        cout<<"d1:function 3"<<endl;
    }
};  
  
class Der2: public Der1 
{  
public: 
Der2(){
    cout<<"Der2 created"<<endl;
 }
   
   void function2() { cout<< "D2 :: function2\n";};
   void function3(){ cout<<"funtion 3 of der 3"<<endl;};
   void function4(){cout<<"function 4"<<endl;};
   void function1(){
    cout<<"d2:function1"<<endl;
   }
};  

int main()
{
  Der2 *d2 = new Der2;
  cout<<"-----"<<endl;
  Der1 *d1 = d2; 

  d1->function1();
  d1->function2();
  d1->function3();
  d1->funtion5();
  //d1->function4(); error
  


  delete (d2);
  
  return (0);
}