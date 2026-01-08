#include<iostream>
#include<cstring>
using namespace std;
class base{
    public: int i;char c; string s;int *iptr;char * cptr;char* cptr2;
    static int st;
    base(){
        cout<<"base called"<<endl;
    }
    base(int a,char c,string s,int *iptr,char* cptr,const char* cptr2){ //constructor
        this->i=a;
        this->c=c;
        this->s=s;
        this->iptr=new int(*iptr);
        this->cptr=new char[strlen(cptr)+1];
        strcpy(this->cptr,cptr);
        this->cptr2=new char[strlen(cptr2)+1];
        strcpy(this->cptr2,cptr2);
    }
    base(base &temp){  
        this->i=temp.i;this->c=temp.c;this->s=temp.s;
        //this->iptr=temp.iptr;this->cptr=temp.cptr; this->cptr2=temp.cptr2;
        this->iptr=new int(*temp.iptr);
        this->cptr=new char[strlen(temp.cptr)+1];
        strcpy(this->cptr,temp.cptr);
        this->cptr2=temp.cptr2; //shallow copy
    }
    base& operator=(const base& temp){
        if(this==& temp)return *this;
        this->i=temp.i;this->c=temp.c;this->s=temp.s;
        delete this->iptr;delete[] this->cptr; delete[] this->cptr2;
        this->iptr=new int(*temp.iptr);
        this->cptr=new char[strlen(temp.cptr)+1];
        strcpy(this->cptr,temp.cptr);
        this->cptr2=temp.cptr2; //shallow copy
        return *this;

    }
    base& operator++(){
        ++i;
        return *this;
    }
    virtual ~base(){
        cout<<"base destructed"<<endl;
    }
};
int base::st=100;
class der1: virtual public base{
    public:
    der1(){
        cout<<"derived1 called"<<endl;
    }
    ~der1(){
        cout<<"derived1 destructed"<<endl;
    }
};
class der2:virtual public base{
    public:
    der2(){cout<<"derived2 called"<<endl;}
     ~der2(){
        cout<<"derived2 destructed"<<endl;
    }
};
class child:public der1,public der2{ public:
    child(){
        cout<<"child called"<<endl;
    }
     ~child(){
        cout<<"child destructed"<<endl;
    }
};

void display(base & b1){
    cout<<b1.i<<" "<<b1.c<<" "<<b1.s<<" "<<*(b1.iptr)<<" "<<b1.cptr<<" "<<b1.cptr2<<endl;
}
int main(){
    int i=100;
    char c='a';
    string s="abhishek";
    int *iptr=&i; 
    char *cptr=new char[s.length()+1]; strcpy(cptr,s.c_str());
    base b1(i,c,s,iptr,cptr,"abhishek2");
    display(b1);
    ++(++b1);
    base b2(b1);
    display(b2); cout<<"------------"<<endl;
    b2.i=200;b2.c='z';b2.s="yadav   "; *b2.iptr=999;b2.cptr[3]='X';
    //delete[] b2.cptr2; b2.cptr2=nullptr;
    display(b1);display(b2);
    b2.cptr[3]='X';
    base *b3=new base(b1);
    display(*b3);
    cout<<"-------"<<endl;
    base* b4=new child();
    delete b4;
    cout<<"-------"<<endl;
}