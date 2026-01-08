#include<iostream>
#include<cstring>
using namespace std;
class cstring{public:
    char* c;    
    cstring(const char *c){
        c=new char[strlen(c+1)];
        strcpy(this->c,c);
    }
    cstring(const cstring& temp){  //copy
        this->c=c;
    }
    cstring& operator=(const cstring & temp){ //copy assignment  //chaining enables
        if (this == &temp) return *this;
        delete[] this->c;
        this->c=c;
        return *this;
    }
    // move related to rvalue
    cstring(cstring&& temp)noexcept{  //move
        c=move(temp.c);
    }
    cstring& operator=(cstring && temp)noexcept{ //move assignment  //chaining enables
        if (this == &temp) return *this;
        delete[] this->c;
        c=move(temp.c);
        return *this;
    }
    ~cstring(){
        delete[] c;
    }
};

int main(){
    const char *c="abhishek";
    cstring s1(c);
    cstring s2(s1);
    cout<<s1.c<<endl;
    cout<<s2.c<<endl;
    s2.c[3]='x';
    cout<<s1.c<<endl;
    cout<<s2.c<<endl;
    cstring s3=s1;
}