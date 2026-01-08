//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
struct minheap{
    int size;
    int capacity;
    int *arr;
    minheap(int capacity){
        this->capacity=capacity;
        arr=new int[capacity];
        size=0;
    }
    int parent(int i){
        return (i-1)/2;
    }
    int lchild(int i){
        return i*2+1;
    }
    int rchild(int i){
        return i*2+2;
    }
    int getmin(){
        return arr[0];
    }
    void insert(int data){
        if(size==capacity) return;
        arr[++size]=data;
        heapify(size-1);
    }
    void heapify(int i=0){
        while(i!=0&&arr[i]<arr[parent(i)]){
            int temp=arr[i];
            arr[i]=arr[parent(i)];
            arr[parent(i)]=temp;
            i=parent(i);
        }
    }
    void decreasekey(int i,int data){
        arr[i]=data;
        heapify(i);
    }
    int extractmin(){
        if(size<=0) return INT_MAX;
        int ans=arr[0];
        
    }
    void deletekey(int i){



    }
    
}
int main(){
    //
    return 0;
}