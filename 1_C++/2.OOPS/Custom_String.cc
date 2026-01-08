#include<iostream>
#include<cstring>
using namespace std;
class cstring{public:
    char* c;    
    cstring(string s){
        c= new char[s.length()+1];
        strcpy(c,s.c_str());
    }
    cstring(const cstring& temp){  //copy
        c=new char[strlen(temp.c)+1];
        strcpy(c,temp.c);
    }
    cstring& operator=(const cstring & temp){ //copy assignment  //chaining enables
        if (this == &temp) return *this;
        delete[] this->c;
        c=new char[strlen(temp.c)+1];
        strcpy(c,temp.c);
        return *this;
    }
    // move related to rvalue
    cstring(cstring&& temp)noexcept{  //move
        c=temp.c;
        temp.c=nullptr;
    }
    cstring& operator=(cstring && temp)noexcept{ //move assignment  //chaining enables
        if (this == &temp) return *this;
        delete[] this->c;
        c=temp.c;
        temp.c=nullptr;
        return *this;
    }
    ~cstring(){
        delete[] c;
    }
};

int main(){
    cstring s1("abhishek");
    cstring s2(s1);
    cout<<s1.c<<endl;
    cout<<s2.c<<endl;
    s2.c[3]='x';
    cout<<s1.c<<endl;
    cout<<s2.c<<endl;
    cstring s3=s1;
}