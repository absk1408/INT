
//Sort funtion internally use quick sort + heap sort + insertion sort 
//TC: (n logn) //internally uses intro sort
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define loop(x,n) for(int i=x;i<n;i++)
using namespace std;
struct Point{
    public:
    int x,y;
};
void print(Point arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i].x<<"-"<<arr[i].y<<" ";
    }
    cout<<endl;
}
bool compare(Point a,Point b){
    return a.y>b.y;
}

int main(){
    Point arr[]={{1,500},{2,300},{3,400}};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,compare);
    print(arr,n);
    return 0;
}
