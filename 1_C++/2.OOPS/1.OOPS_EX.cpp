//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
class Base{
    public:
    int a;
    char* c;
   
    int strlen1(const char* c){
        int res=0;
        while(c[res]!='\0'){
            res++;
        }
        return res;
    }
    void strcpy1(char* s,const char* d){
        delete[] s;
        s=new char[strlen1(d)+1];
        int i=0;
        while(d[i]!='\0'){
            s[i]=d[i];
            i++;
        }
        s[i]='\0';
    }
    void strcat1(char* s,const char* d){
        int len1=strlen1(s); int len2=strlen1(d);
        char* new_c=new char[len1+len2];
        strcpy1(new_c,s);
        int i=0;
        while(d[i]!='\0'){
            new_c[len1]=d[i];i++;len1++;
        }
        s[len1]='\0';
        strcpy1(s,new_c);
    }
     Base(){
        c=nullptr;
    }
    Base(int a1,const char* c1){
        if (!c1 || strlen1(c1) == 0) {
            throw invalid_argument("Invalid input: c1 cannot be null or empty.");
        }
        a=a1;
        c=new char[strlen1(c1)+1];
        strcpy1(c,c1);
    }
    void show(){
        cout<<a<<" "<<c<<endl;
    }
    //resolution
    Base(Base& temp){
        c=new char(strlen1(temp.c)+1);
        strcpy1(c,temp.c);
        a=temp.a;
    }
    Base operator+(const char* c1){
        char* new_c=new char[strlen1(c1)+strlen1(c)+1];
        // cout<<strlen(c)<<endl;
        // int i=strlen(c);
        // int j=0;
        // while(c1[j]!='\0'){
        //     c[i]=c1[j];
        //     i++;j++;
        // }
        // c[j]='\0';
        // cout<<c<<endl;
        // return *this;
        strcpy1(new_c,c);
        strcat1(new_c,c1);
        delete[] c;
        c=new_c;
        return *this;
    }
};
int main(){
    try{
    Base ob0;
    Base ob1(100,"abhishek");
    Base obj2=ob1+" yadav";
    obj2.show();
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}