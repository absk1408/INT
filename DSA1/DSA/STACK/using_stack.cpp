///////////////////////////
/*
limitations:
1.maximum size of stack must be defined and if its full its going to throw exceptions.
*/
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
using namespace std;

struct ArrayStack{
    int top;
    int cap;
    int* arr;
    ArrayStack(int l){
        cap=l;
        arr=new int[l];
        top=-1;
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==(cap-1);
    }
    void push(int data){
        if(isFull()) cout<<"stackoverflow"<<endl;
        else arr[++top]=data;
    }
    int pop(){
        int ans;
        if(isEmpty())cout<<"stackunderflow"<<endl;
        else ans=arr[top--];
        return ans;
    }
    void deleteStack(){
        delete[] arr;
        cap=0;
    }
    int topE(){
        return arr[top];
    }
};
int main(){
    ArrayStack st(10);
    st.push(10);
    st.push(100);
    int top=st.pop();
    cout<<top<<endl;
    st.deleteStack();
    st.push(10000);
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    return 0;
}
