#include<iostream>
using namespace std;
int main(){
    int b=100;
    int *p=&b;
    int arr[2]={1,2};
    cout<<arr<<" "<<&arr<<" "<<&arr[0]<<endl;
    cout<<arr+1<<" "<<&arr[0]+1<<endl;
    cout<<&arr+1<<endl;  //skips the whole array ..
    return 0;
}